#include "gameStatus.h"

//ÿ��������С����ĸ߿�
const int GameStatus::paneHeight = 30;
const int GameStatus::paneWidth= 30;

//���Ӱ뾶
const int GameStatus::pieceSize = 24;

//��Ϸ�������  m x m
const int GameStatus::gameCellCount = 19;
//��Ԫ�����С
const int GameStatus::gameCellSize = 30;

//��ͼƫ���������������
const int GameStatus::paintOffset_H = 20;
const int GameStatus::paintOffset_W = 20;

//���λ��ƫ���������������
const int GameStatus::mouseMoveOffset_H = 25;
const int GameStatus::mouseMoveOffset_W = 17;

//����귶Χ��ƫ��
const int GameStatus::halfCellWidth = 2 * gameCellSize / 3;
const int GameStatus::frameWidth = gameCellSize / 6;

GameStatus::GameStatus(QWidget *parent, Qt::WFlags flags) 
						: QDialog(parent, flags), tcpServer_player(NULL),
						tcpSocket_player(NULL), tcpSocket_server(NULL),
						win(0), lose(0), plyStatus(readyToPlayingGame),
						closeByServer(false), whosTurn(HOST)
{
	ui.setupUi(this);

	widgetInit();
}

GameStatus::~GameStatus()
{
}

void GameStatus::closeEvent(QCloseEvent *event)
{
	if(closeByServer)
	{
		timer.stop();
		dataInit();
		ui.gameReady_client_BTN->setDisabled(false);
		ui.undo_client_BTN->setDisabled(true);
		ui.lose_client_BTN->setDisabled(true);
		ui.send_client_BTN->setDisabled(true);
		QMessageBox::information(NULL,"�˳�","����˳�����Ϸ������");
	}
	else
	{
		if(!DataClass::checkDialog("�˳�","ȷ���˳���Ϸ��"))
		{
			event->ignore();
			return ;
		}
		timer.stop();
		dataInit();
		ui.gameReady_client_BTN->setDisabled(false);
		ui.undo_client_BTN->setDisabled(true);
		ui.lose_client_BTN->setDisabled(true);
		ui.send_client_BTN->setDisabled(true);
		//�����˳���Ϸ֪ͨ
		if(plyRole == GUEST)
		{
			//�رպ�HOST��������
			//Ȼ����HOST�������˳���Ϣ
			DataClass::sendMsg(COMM_CLIENT_QUITGAME,"GUEST",tcpSocket_server);
			if(tcpSocket_player)
			{
				DataClass::sendMsg(COMM_CLIENT_QUITGAME,"",tcpSocket_player);
				tcpSocket_player->close();
				tcpSocket_player = NULL;
			}
		}
		else if(plyRole == HOST)
		{
			//�رպ�GUEST��������
			//Ȼ����GUEST�������˳���Ϣ
			DataClass::sendMsg(COMM_CLIENT_QUITGAME,"HOST",tcpSocket_server);
			if(tcpSocket_player)
			{
				DataClass::sendMsg(COMM_CLIENT_QUITGAME,"",tcpSocket_player);
				tcpSocket_player->close();
				tcpSocket_player = NULL;
			}
			if(tcpServer_player)
			{
				tcpServer_player->close();
				tcpServer_player = NULL;
			}
		}
	}
	//code here
	//���tcpServer_player �� tcpSocket_player��ΪNULL�Ļ� ��Ҫ����
	event->accept();
}

void GameStatus::dataInit()
{
	for(int i=0; i<19; i++)
		for(int j=0; j<19; j++)
			chessboardRecord[i][j] = 0;
	pieceRecord.clear();
}

void GameStatus::widgetInit()
{
	for(int i=0; i<gameCellCount; i++)
		for(int j=0; j<gameCellCount; j++)
			chessboardRecord[i][j] = 0;

	//�����Լ�����Ϣ
	ui.addr_me_client_LE->setText("127.0.0.1");
	ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");

	//͸����ͼ�����QGroupBox
// 	QPalette palette;
// 	QBrush brush(QColor(0, 0, 0, 0));
// 	brush.setStyle(Qt::SolidPattern);
// 	palette.setBrush(QPalette::All, QPalette::Base, brush);
//	ui.gameArea_client_GPB->setPalette(palette);
}

void GameStatus::setPlayerInfo(QString rivarAddr)
{
	//�����Լ�����Ϣ
	ui.addr_me_client_LE->setText("127.0.0.1");
	ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");

	//���ö��ֵ���Ϣ
	ui.addr_rivar_client_LE->setText(rivarAddr);
	ui.record_rivar_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
}

void GameStatus::setPlayerRole(playerRole _plyRole)
{
	//������֮�������
	//���plyRole��HOST�Ļ�������һ���µļ����ȴ��Է�����
	//���plyRole��GUTST�Ļ�������һ��������������
	plyRole = _plyRole;
	win = lose = 0;
	ui.chatLog_client_TE->clear();
	closeByServer = false;
	ui.gameStatus_client_LB->setText("");
	plyStatus = readyToPlayingGame;
	if(plyRole == HOST)
	{
		ui.addr_rivar_client_LE->setText("");
		ui.record_rivar_client_LE->setText("");
		ui.color_me_client_LE->setText("��ɫ");
		ui.color_rivar_client_LE->setText("��ɫ");
		tcpServer_player = new QTcpServer(this);
		if(!(tcpServer_player->listen(QHostAddress::Any, DataClass::connPort - 1)))
		{
			QMessageBox::information(this,"����","���������˿�ʧ�ܣ�");
			this->hide();
			return ;
		}
		connect(tcpServer_player, SIGNAL(newConnection()), this, SLOT(getNewConn()));

		ui.gameReady_client_BTN->setDisabled(true);
	}
	else if(plyRole == GUEST)
	{
		ui.color_me_client_LE->setText("��ɫ");
		ui.color_rivar_client_LE->setText("��ɫ");
		tcpSocket_player = new QTcpSocket(this);
		tcpSocket_player->connectToHost(ui.addr_rivar_client_LE->text(),DataClass::connPort - 1);
		//���ӳɹ�
		connect(tcpSocket_player,SIGNAL(connected()),this,SLOT(connSuccessful()));
		//���ӳ���
		connect(tcpSocket_player,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(connFailed()));
	}
}

void GameStatus::getNewConn()
{
	tcpSocket_player = tcpServer_player->nextPendingConnection();
	connect(tcpSocket_player, SIGNAL(readyRead()), this, SLOT(getNewDataFromClient()));
	ui.send_client_BTN->setDisabled(false);
}

void GameStatus::connSuccessful()
{
	connect(tcpSocket_player, SIGNAL(readyRead()), this, SLOT(getNewDataFromClient()));
	ui.send_client_BTN->setDisabled(false);
}

void GameStatus::connFailed()
{
	//��������������ʧ��
// 	QMessageBox::information(NULL,"����","��������������ʧ�ܣ�");
// 	return ;
}

void GameStatus::setPara(QTcpSocket* _tcpSocket_server)
{
	tcpSocket_server = _tcpSocket_server;
}

void GameStatus::getNewDataFromClient()
{
	timer.stop();
	QDataStream in;
	msg_req_struct = new msg_request_struct();
	in.setDevice(tcpSocket_player);
	in >> msg_req_struct->request >> msg_req_struct->data;

	switch(msg_req_struct->request)
	{
	case COMM_CLIENT_QUITGAME:
		recvMsg_quitGame();
		break;
	case COMM_CLIENT_GAMESTART:
		recvMsg_gameStart();
		break;
	case COMM_CLIENT_GAMEOP:
		recvMsg_gameOP();
		break;
	case COMM_CLIENT_LOSE:
		recvMsg_lose();
		break;
	case COMM_CLIENT_GAMEOVER:
		recvMsg_gameOver();
		break;
	case COMM_CLIENT_CHAT:
		recvMsg_chat();
		break;
	case COMM_CLIENT_UNDO:
		recvMsg_undo();
		break;
	case COMM_CLIENT_UNDO_YES:
		recvMsg_undoYes();
		break;
	case COMM_CLIENT_UNDO_NO:
		recvMsg_undoNo();
		break;
	default:
		break;
	}
}

void GameStatus::recvMsg_quitGame()
{
	dataInit();
	ui.undo_client_BTN->setDisabled(true);
	ui.lose_client_BTN->setDisabled(true);
	ui.send_client_BTN->setDisabled(true);
	if(plyRole == HOST)
	{
		plyStatus = readyToPlayingGame;
		ui.chatLog_client_TE->clear();
		ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
		ui.record_rivar_client_LE->setText("");
		ui.addr_rivar_client_LE->setText("");
		QMessageBox::information(NULL,"��ʾ","�Է��˳���Ϸ��");
	}
	else if(plyRole == GUEST)
	{
		ui.gameReady_client_BTN->setDisabled(false);
		closeByServer = true;
		this->close();
	}
}

void GameStatus::recvMsg_gameStart()
{
	dataInit();
	ui.gameReady_client_BTN->setDisabled(true);
	ui.undo_client_BTN->setDisabled(false);
	ui.lose_client_BTN->setDisabled(false);
	ui.send_client_BTN->setDisabled(false);
	ui.gameStatus_client_LB->setText("��Ϸ��ʼ��");
	plyStatus = playingGame;
	whosTurn = HOST;
	ui.lose_client_BTN->setDisabled(false);
	ui.undo_client_BTN->setDisabled(false);
}

void GameStatus::recvMsg_gameOP()
{	
	int pos = msg_req_struct->data.indexOf("_");
	int x = msg_req_struct->data.mid(0,pos).toInt();
	int y = msg_req_struct->data.mid(pos + 1, msg_req_struct->data.size() - pos).toInt();
	chessboardRecord[x - 1][y - 1] = (plyRole == HOST? -1 : 1);
	pieceRecord.push_back(qMakePair(QPoint(x,y), plyRole == HOST ? GUEST : HOST));
	whosTurn = plyRole;
	ui.gameStatus_client_LB->setText("���������ˣ�");

	update();
}

void GameStatus::recvMsg_lose()
{
	QMessageBox::information(NULL,"ʤ��","�Է����䣡");
	ui.gameStatus_client_LB->setText("�Է����䣡");
	win += 1;
	ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
	ui.record_rivar_client_LE->setText("ʤ����" + QString::number(lose) + "����ʧ�ܣ�" + QString::number(win) + "����");
	if(plyRole == GUEST)
		ui.gameReady_client_BTN->setDisabled(false);
	ui.undo_client_BTN->setDisabled(true);
	ui.lose_client_BTN->setDisabled(true);
	plyStatus = readyToPlayingGame;
}

void GameStatus::recvMsg_gameOver()
{
	QMessageBox::information(NULL,"ʤ��","�Է�ʤ����");
	ui.gameStatus_client_LB->setText("�Է�ʤ����");
	lose += 1;
	ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
	ui.record_rivar_client_LE->setText("ʤ����" + QString::number(lose) + "����ʧ�ܣ�" + QString::number(win) + "����");
	if(plyRole == GUEST)
		ui.gameReady_client_BTN->setDisabled(false);
	ui.undo_client_BTN->setDisabled(true);
	ui.lose_client_BTN->setDisabled(true);
	plyStatus = readyToPlayingGame;
}

void GameStatus::recvMsg_chat()
{
	ui.chatLog_client_TE->append("���֣�  " + msg_req_struct->data);
}

void GameStatus::recvMsg_undo()
{
	if(DataClass::checkDialog("��������","�Ƿ��Ӧ�Է���������"))
	{
		DataClass::sendMsg(COMM_CLIENT_UNDO_YES,"",tcpSocket_player);
		if(pieceRecord.size() > 0)
		{	
			chessboardRecord[pieceRecord[pieceRecord.size() - 1].first.x()-1][pieceRecord[pieceRecord.size() - 1].first.y()-1] = 0;
			pieceRecord.removeAt(pieceRecord.size() - 1);
		}
		if(pieceRecord.size() > 0)
		{	
			chessboardRecord[pieceRecord[pieceRecord.size() - 1].first.x()-1][pieceRecord[pieceRecord.size() - 1].first.y()-1] = 0;
			pieceRecord.removeAt(pieceRecord.size() - 1);
		}
		update();
	}
	else
		DataClass::sendMsg(COMM_CLIENT_UNDO_NO,"",tcpSocket_player);
}

void GameStatus::recvMsg_undoYes()
{
	QMessageBox::information(NULL,"��ʾ","�Է�ͬ����壡");
	whosTurn = plyRole;
	if(pieceRecord.size() > 0)
	{
		chessboardRecord[pieceRecord[pieceRecord.size() - 1].first.x()-1][pieceRecord[pieceRecord.size() - 1].first.y()-1] = 0;
		pieceRecord.removeAt(pieceRecord.size() - 1);
	}
	if(pieceRecord.size() > 0)
	{
		chessboardRecord[pieceRecord[pieceRecord.size() - 1].first.x()-1][pieceRecord[pieceRecord.size() - 1].first.y()-1] = 0;
		pieceRecord.removeAt(pieceRecord.size() - 1);
	}
	update();
}

void GameStatus::recvMsg_undoNo()
{
	whosTurn = plyRole;
	QMessageBox::information(NULL,"����","�Է���ͬ���������!");
}

void GameStatus::getNewDataFromServer()
{
	QDataStream in;
	msg_req_struct = new msg_request_struct();
	in.setDevice(tcpSocket_server);
	in >> msg_req_struct->request >> msg_req_struct->data;

	switch (msg_req_struct->request)
	{
	case COMM_CLIENT_JOIN:
		setPlayerInfo(msg_req_struct->data);
		break;
	default:
		break;
	}

	delete msg_req_struct;
	msg_req_struct = NULL;
}

void GameStatus::on_quit_client_BTN_clicked()
{
	closeByServer = false;
	this->close();
}

void GameStatus::on_send_client_BTN_clicked()
{
	if(ui.sendwords_client_LE->text() == "")
	{
		QMessageBox::information(NULL,"����","�����������֣�");
		return ;
	}
	ui.chatLog_client_TE->append("�Լ���  " + ui.sendwords_client_LE->text());
	DataClass::sendMsg(COMM_CLIENT_CHAT,ui.sendwords_client_LE->text(),tcpSocket_player);
	ui.sendwords_client_LE->setText("");
}

void GameStatus::on_lose_client_BTN_clicked()
{
	if(!(DataClass::checkDialog("ȷ��","ȷ�����䣿")))
		return ;
	DataClass::sendMsg(COMM_CLIENT_LOSE,"",tcpSocket_player);		
	
	if(plyRole == GUEST)
		ui.gameReady_client_BTN->setDisabled(false);
	ui.undo_client_BTN->setDisabled(true);
	ui.lose_client_BTN->setDisabled(true);
	plyStatus = readyToPlayingGame;
	lose += 1;
	ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
	ui.record_rivar_client_LE->setText("ʤ����" + QString::number(lose) + "����ʧ�ܣ�" + QString::number(win) + "����");
	return ;
}

void GameStatus::on_undo_client_BTN_clicked()
{
	if(whosTurn != plyRole)
	{
		QMessageBox::information(NULL,"����","�ֵ��������ʱ������ܷ�����������");
		return ;
	}
	if(!(DataClass::checkDialog("ȷ��","ȷ�ϻ��壿")))
		return ;
	whosTurn = (plyRole == HOST ? GUEST : HOST);
	DataClass::sendMsg(COMM_CLIENT_UNDO,"",tcpSocket_player);
}

void GameStatus::on_gameReady_client_BTN_clicked()
{
	if(plyRole == GUEST)
	{
		whosTurn = HOST;
		ui.gameStatus_client_LB->setText("��Ϸ��ʼ��");
		plyStatus = playingGame;
		DataClass::sendMsg(COMM_CLIENT_GAMESTART,"",tcpSocket_player);
		dataInit();
		ui.gameReady_client_BTN->setDisabled(true);
		ui.lose_client_BTN->setDisabled(false);
		ui.undo_client_BTN->setDisabled(false);
		ui.send_client_BTN->setDisabled(false);
	}
}

void GameStatus::paintEvent(QPaintEvent *)
{
 	QPainter painter(this);
	drawGrid(&painter);
	drawMouseArea(&painter);
	drawPieceRecord(&painter);
}

void GameStatus::mousePressEvent(QMouseEvent *)
{
	if(plyStatus != playingGame)
	{
		ui.gameStatus_client_LB->setText("��Ϸ��δ��ʼ��");
		return ;
	}
	if(whosTurn != plyRole)
	{
		ui.gameStatus_client_LB->setText("���ڸöԷ�������");
		return ;
	}
	QPoint point = mapFromGlobal(QCursor::pos());
	int curArrPos_x, curArrPos_y;
	curArrPos_x = qRound(float(point.x() - mouseMoveOffset_H) / gameCellSize);
	curArrPos_y = qRound(float(point.y() - mouseMoveOffset_W) / gameCellSize);
	if(curArrPos_x < 1 || curArrPos_x > 19 || curArrPos_y < 1 || curArrPos_y > 19)
		return ;
	if(chessboardRecord[curArrPos_x - 1][curArrPos_y - 1] != 0)
	{
		ui.gameStatus_client_LB->setText("�˴��������ӣ�");
		return ;
	}
	chessboardRecord[curArrPos_x - 1][curArrPos_y - 1] = (plyRole == HOST? 1 : -1);

	QPoint point_tmp(curArrPos_x, curArrPos_y);
	pieceRecord.push_back(qMakePair(point_tmp, plyRole));
	update();
	//����Ƿ�ʤ��
	if(checkWin())
	{
		DataClass::sendMsg(COMM_CLIENT_GAMEOVER, "", tcpSocket_player);
		QMessageBox::information(NULL,"ʤ��","��ʤ���ˣ�");
		ui.gameStatus_client_LB->setText("��ʤ���ˣ�");
		if(plyRole == GUEST)
			ui.gameReady_client_BTN->setDisabled(false);
		ui.undo_client_BTN->setDisabled(true);
		ui.lose_client_BTN->setDisabled(true);
		plyStatus = readyToPlayingGame;
		win += 1;
		ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
		ui.record_rivar_client_LE->setText("ʤ����" + QString::number(lose) + "����ʧ�ܣ�" + QString::number(win) + "����");
		return ;
	}
	ui.gameStatus_client_LB->setText("�öԷ������ˣ�");
	whosTurn = (whosTurn == HOST? GUEST : HOST);
	//���͸ոյ�������Ϣ
	DataClass::sendMsg(COMM_CLIENT_GAMEOP, QString::number(curArrPos_x) + "_" + QString::number(curArrPos_y), tcpSocket_player);

	connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
	timer.start(30000);
}

void GameStatus::timeout()
{
	//������Socket����Ч��˵����ʵû�г�ʱ��ֻ�ǶԷ���֪������ȥ�ˣ�
	if(tcpSocket_player->isValid())
		return ;

	QMessageBox::information(NULL,"��ʾ","�Է���ʱ!");
	dataInit();
	ui.undo_client_BTN->setDisabled(true);
	ui.lose_client_BTN->setDisabled(true);
	ui.send_client_BTN->setDisabled(true);
	//���ͶԷ��˳���Ϸ֪ͨ
	if(plyRole == GUEST)
	{
		DataClass::sendMsg(COMM_CLIENT_LOSTCONN,"HOST " + ui.addr_rivar_client_LE->text(),tcpSocket_server);
		if(tcpSocket_player)
		{
			tcpSocket_player->close();
			tcpSocket_player = NULL;
		}
		this->close();
	}
	else if(plyRole == HOST)
	{
		DataClass::sendMsg(COMM_CLIENT_LOSTCONN,"GUEST " + ui.addr_rivar_client_LE->text(),tcpSocket_server);
		plyStatus = readyToPlayingGame;
		ui.chatLog_client_TE->clear();
		ui.record_me_client_LE->setText("ʤ����" + QString::number(win) + "����ʧ�ܣ�" + QString::number(lose) + "����");
		ui.record_rivar_client_LE->setText("");
		ui.addr_rivar_client_LE->setText("");
		if(tcpSocket_player)
		{
			tcpSocket_player->close();
			tcpSocket_player = NULL;
		}
		if(tcpServer_player)
		{
			tcpServer_player->close();
			tcpServer_player = NULL;
		}
	}
}

bool GameStatus::checkWin()
{
	int last_x = pieceRecord[pieceRecord.size() - 1].first.x() - 1;
	int last_y = pieceRecord[pieceRecord.size() - 1].first.y() - 1;
	int winColor = (plyRole == HOST ? 1 : -1);
	if(checkWinLURD(last_x, last_y, winColor))
		return true;
	if(checkWinUD(last_x, last_y, winColor))
		return true;
	if(checkWinRULD(last_x, last_y, winColor))
		return true;
	if(checkWinRL(last_x, last_y, winColor))
		return true;
	return false;
}

bool GameStatus::checkWinLURD(int last_x, int last_y, int winColor)
{
	for(int j=4; j>-1; j--)
	{
		if(last_x - j <0 || last_y - j < 0)
			continue;
		for(int z=0; z<5; z++)
		{
			if(last_x - j + z > 18 || last_y - j + z > 18)
				break;
			if(chessboardRecord[last_x - j + z][last_y - j + z] != winColor)
				break;
			else if(z == 4)
				return true;
		}
	}
	return false;
}

bool GameStatus::checkWinUD(int last_x, int last_y, int winColor)
{
	for(int j=4; j>-1; j--)
	{
		if(last_y - j < 0)
			continue;
		for(int z=0; z<5; z++)
		{
			if(last_y - j + z > 18)
				break;
			if(chessboardRecord[last_x][last_y - j + z] != winColor)
				break;
			else if(z == 4)
				return true;
		}
	}
	return false;
}

bool GameStatus::checkWinRULD(int last_x, int last_y, int winColor)
{
	for(int j=4; j>-1; j--)
	{
		if(last_x + j > 18 || last_y - j < 0)
			continue;
		for(int z=0; z<5; z++)
		{
			if(last_x + j - z < 0 || last_y - j + z > 18)
				break;
			if(chessboardRecord[last_x + j - z][last_y - j + z] != winColor)
				break;
			else if(z == 4)
				return true;
		}
	}
	return false;
}

bool GameStatus::checkWinRL(int last_x, int last_y, int winColor)
{
	for(int j=4; j>-1; j--)
	{
		if(last_x + j > 18)
			continue;
		for(int z=0; z<5; z++)
		{
			if(last_x + j - z < 0)
				break;
			if(chessboardRecord[last_x + j - z][last_y] != winColor)
				break;
			else if(z == 4)
				return true;
		}
	}
	return false;
}

void GameStatus::drawPieceRecord(QPainter* painter)
{
	for(int i=0; i<pieceRecord.size(); i++)
	{
		painter->setBrush(QBrush(pieceRecord[i].second == HOST ? Qt::black : Qt::white,Qt::SolidPattern));
		painter->setPen(Qt::black);
		int x = pieceRecord[i].first.x() * gameCellSize + mouseMoveOffset_H - 6;
		int y = pieceRecord[i].first.y() * gameCellSize + mouseMoveOffset_W + 2;
		painter->drawEllipse(x - pieceSize / 2,y  - pieceSize / 2, pieceSize, pieceSize);
	}

	if(pieceRecord.size() == 0)
		return ;
	int x = pieceRecord[pieceRecord.size() - 1].first.x() * gameCellSize + mouseMoveOffset_H - 6;
	int y = pieceRecord[pieceRecord.size() - 1].first.y() * gameCellSize + mouseMoveOffset_W + 2;
	painter->setPen(QPen(Qt::red,2));
	painter->drawLine(x - halfCellWidth, y - halfCellWidth, x - frameWidth, y - halfCellWidth);
	painter->drawLine(x - halfCellWidth, y + halfCellWidth, x - frameWidth, y + halfCellWidth);
	painter->drawLine(x + frameWidth, y - halfCellWidth, x + halfCellWidth, y - halfCellWidth);
	painter->drawLine(x + frameWidth, y + halfCellWidth, x + halfCellWidth, y + halfCellWidth);
	painter->drawLine(x - halfCellWidth, y - halfCellWidth, x - halfCellWidth, y - frameWidth);
	painter->drawLine(x - halfCellWidth, y + frameWidth, x - halfCellWidth, y + halfCellWidth);
	painter->drawLine(x + halfCellWidth, y - halfCellWidth, x + halfCellWidth, y - frameWidth);
	painter->drawLine(x + halfCellWidth, y + frameWidth, x + halfCellWidth, y + halfCellWidth);
}

void GameStatus::drawMouseArea(QPainter* painter)
{
	QPoint point = mapFromGlobal(QCursor::pos());
	int curArrPos_x, curArrPos_y;
	curArrPos_x = qRound(float(point.x() - mouseMoveOffset_H) / gameCellSize);
	curArrPos_y = qRound(float(point.y() - mouseMoveOffset_W) / gameCellSize);
	if(curArrPos_x < 1 || curArrPos_x > 19 || curArrPos_y < 1 || curArrPos_y > 19)
	{
		this->setCursor(QCursor(Qt::ArrowCursor));
		return ;
	}

	this->setCursor(QCursor(Qt::PointingHandCursor));
	int x, y;
	x = curArrPos_x* gameCellSize + mouseMoveOffset_H - 6;
	y = curArrPos_y* gameCellSize + mouseMoveOffset_W + 2;

	painter->setPen(QPen(Qt::green,1));
	painter->drawLine(x - halfCellWidth, y - halfCellWidth, x - frameWidth, y - halfCellWidth);
	painter->drawLine(x - halfCellWidth, y + halfCellWidth, x - frameWidth, y + halfCellWidth);
	painter->drawLine(x + frameWidth, y - halfCellWidth, x + halfCellWidth, y - halfCellWidth);
	painter->drawLine(x + frameWidth, y + halfCellWidth, x + halfCellWidth, y + halfCellWidth);
	painter->drawLine(x - halfCellWidth, y - halfCellWidth, x - halfCellWidth, y - frameWidth);
	painter->drawLine(x - halfCellWidth, y + frameWidth, x - halfCellWidth, y + halfCellWidth);
	painter->drawLine(x + halfCellWidth, y - halfCellWidth, x + halfCellWidth, y - frameWidth);
	painter->drawLine(x + halfCellWidth, y + frameWidth, x + halfCellWidth, y + halfCellWidth);
	update();
}

void GameStatus::drawGrid(QPainter* painter)
{
	//�Ȼ���߿�
	int i=0;
	painter->setPen(QPen(Qt::black,4));
	painter->drawLine(i * gameCellSize + paintOffset_H, paintOffset_W, i * gameCellSize + paintOffset_H, 
		gameCellSize * (gameCellCount + 1) + paintOffset_W);

	//�ٻ�������
	painter->setPen(QPen(Qt::blue,2));
	for(i=1; i<gameCellCount + 1; i++)
	{
		painter->drawLine(i * gameCellSize + paintOffset_H, paintOffset_W, i * gameCellSize + paintOffset_H, 
			gameCellSize * (gameCellCount + 1) + paintOffset_W);
	}

	//����ұ߿�
	painter->setPen(QPen(Qt::black,4));
	painter->drawLine(i * gameCellSize + paintOffset_H, paintOffset_W, i * gameCellSize + paintOffset_H, 
		gameCellSize * (gameCellCount + 1) + paintOffset_W);


	//�Ȼ��ϱ߿�
	int j=0;
	painter->setPen(QPen(Qt::black,4));
	painter->drawLine(paintOffset_H + 3, j* gameCellSize + paintOffset_W, 
		gameCellSize * (gameCellCount + 1) + paintOffset_H - 3, j * gameCellSize + paintOffset_W);

	//�ٻ�������
	painter->setPen(QPen(Qt::blue,2));
	for(j=1; j<gameCellCount + 1; j++)
	{
		painter->drawLine(paintOffset_H + 3, j* gameCellSize + paintOffset_W, 
			gameCellSize * (gameCellCount + 1) + paintOffset_H - 3, j * gameCellSize + paintOffset_W);
	}

	//����±߿�
	painter->setPen(QPen(Qt::black,4));
	painter->drawLine(paintOffset_H + 3, j* gameCellSize + paintOffset_W, 
		gameCellSize * (gameCellCount + 1) + paintOffset_H - 3, j * gameCellSize + paintOffset_W);
}