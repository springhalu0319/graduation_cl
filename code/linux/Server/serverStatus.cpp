#include "serverStatus.h"

ServerStatus::ServerStatus(QWidget *parent, Qt::WFlags flags) 
										 : QDialog(parent, flags), tcpServer_player(NULL)
{
	ui.setupUi(this);

	widgetInit();
}

ServerStatus::~ServerStatus()
{
	if(tcpServer_player)
	{
		QList<QTcpSocket *> allTcpSocket = tcpServer_player->findChildren<QTcpSocket *>();
		for(int i=0; i<allTcpSocket.size(); i++)
		{
			allTcpSocket[i]->close();
			allTcpSocket[i] = NULL;
		}
		tcpServer_player->close();
		tcpServer_player = NULL;
	}
}

void ServerStatus::closeEvent(QCloseEvent *event)
{
	if(!DataClass::checkDialog("�˳�","ȷ�Ϲرշ���"))
	{
		event->ignore();
		return ;
	}
	emit stopService();
}

void ServerStatus::widgetInit()
{
	ui.curConnCount_server_LE->setText("0");
	updateGameInfo();
}

void ServerStatus::setPara(QTcpServer *_tcpServer_player)
{
	tcpServer_player = _tcpServer_player;
}

void ServerStatus::on_closeServer_server_BTN_clicked()
{
	if(!DataClass::checkDialog("�˳�","ȷ�Ϲرշ���"))
		return ;
	emit stopService();
}

void ServerStatus::getNewConn()
{
	QTcpSocket *tcpSocket_player = tcpServer_player->nextPendingConnection();
//	DataClass::dbgBox(1,tcpSocket_player->peerAddress().toString());

	DataClass::curConnCount++;
	if(DataClass::curConnCount > DataClass::maxConnectionLimit)
	{
		//�������ﵽ�������������
		DataClass::curConnCount--;
		tcpSocket_player->close();
		tcpSocket_player = NULL;
		return ;
	}
	
	ui.curConnCount_server_LE->setText(QString::number(DataClass::curConnCount));

	sendGameInfo(tcpSocket_player);
	DataDisposalThread *dataDisposalThread = new DataDisposalThread(NULL);
	dataDisposalThread->setPara(tcpSocket_player);
	connect(dataDisposalThread, SIGNAL(updateCurConnCount()), this, SLOT(updateCurConnCount()));
	connect(dataDisposalThread, SIGNAL(createRoom(QString)), this, SLOT(createRoom(QString)));
	connect(dataDisposalThread, SIGNAL(quitRoom(QString, QString)), this, SLOT(quitRoom(QString, QString)));
	connect(dataDisposalThread, SIGNAL(joinRoom(QString, QString)), this, SLOT(joinRoom(QString, QString)));
	connect(tcpSocket_player, SIGNAL(readyRead()), dataDisposalThread, SLOT(start()));

	//�������ݹ���ʱ��Ӧ�ĺ���
	//connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getNewData()));
}

void ServerStatus::updateCurConnCount()
{
	ui.curConnCount_server_LE->setText(QString::number(DataClass::curConnCount));
}

void ServerStatus::createRoom(QString clientAddr)
{
	QString qsNull = "-";
	playerFightInfo.push_back(qMakePair(clientAddr, qsNull));
	updateGameInfo();
	QList<QTcpSocket* > allTcpSocket = tcpServer_player->findChildren<QTcpSocket *>();
	for(int i=0; i<allTcpSocket.size(); i++)
		sendGameInfo(allTcpSocket[i]);
}

void ServerStatus::sendGameInfo(QTcpSocket* tcpSocket)
{
	QString data;
	for(int i=0; i<playerFightInfo.size(); i++)
		data += playerFightInfo[i].first + " " + playerFightInfo[i].second + "_";

	DataClass::sendMsg(COMM_SERVER_GAMEINFO, data, tcpSocket);
}

void ServerStatus::quitRoom(QString plyRole, QString clientAddr)
{
	for(int i=0; i<playerFightInfo.size(); i++)
	{
		if(plyRole == "GUEST")
		{
			if(playerFightInfo[i].second == clientAddr)
			{
				playerFightInfo[i].second = "-";
				updateGameInfo();
				//�Ż���ֻ���͸�����������ð����еĶ�����ȥ
				QList<QTcpSocket* > allTcpSocket = tcpServer_player->findChildren<QTcpSocket *>();
				for(int i=0; i<allTcpSocket.size(); i++)
					sendGameInfo(allTcpSocket[i]);
			}
		}
		else if(plyRole == "HOST")
		{
			if(playerFightInfo[i].first == clientAddr)
			{
				playerFightInfo.removeAt(i);
				updateGameInfo();
				//�Ż���ֻ���͸�����������ð����еĶ�����ȥ
				QList<QTcpSocket* > allTcpSocket = tcpServer_player->findChildren<QTcpSocket *>();
				for(int i=0; i<allTcpSocket.size(); i++)
					sendGameInfo(allTcpSocket[i]);
			}
		}
	}
}

void ServerStatus::joinRoom(QString hostAddr, QString guestAddr)
{
	for(int i=0; i<playerFightInfo.size(); i++)
	{
		if(playerFightInfo[i].first == hostAddr)
		{
			playerFightInfo[i].second = guestAddr;
			updateGameInfo();
			QList<QTcpSocket* > allTcpSocket = tcpServer_player->findChildren<QTcpSocket *>();
			for(int i=0; i<allTcpSocket.size(); i++)
			{
				sendGameInfo(allTcpSocket[i]);
				if(allTcpSocket[i]->peerAddress().toString() == hostAddr)
					DataClass::sendMsg(COMM_CLIENT_JOIN, guestAddr, allTcpSocket[i]);
			}
		}
	}
}

void ServerStatus::updateGameInfo()
{
	ui.clientStatus_server_TBW->setRowCount(0);
	for(int i=0; i<playerFightInfo.size(); i++)
	{
		QTableWidgetItem *player1, *player2, *playStatus;
		int row = ui.clientStatus_server_TBW->rowCount();
		ui.clientStatus_server_TBW->setRowCount(row + 1);
		player1 = new QTableWidgetItem(playerFightInfo[i].first);
		player1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
		ui.clientStatus_server_TBW->setItem(row,0,player1);
		player2 = new QTableWidgetItem(playerFightInfo[i].second);
		player2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
		ui.clientStatus_server_TBW->setItem(row,1,player2);
		playStatus = new QTableWidgetItem(playerFightInfo[i].second == "-" ? "�ȴ����" : "��ս��");
		playStatus->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
		ui.clientStatus_server_TBW->setItem(row,2,playStatus);
	}
}