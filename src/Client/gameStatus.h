#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <QtGui/QMainWindow>

#include "dataClass.h"
#include "ui_gameStatus.h"

class GameStatus : public QDialog
{
	Q_OBJECT

public:
	GameStatus(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GameStatus();

	//���ò���
	void setPara(QTcpSocket* _tcpSocket_server);
	//���ö�����Ϣ
	void setPlayerInfo(QString rivarAddr);
	//���õ�ǰ������Ϸ��� ������
	void setPlayerRole(playerRole _plyRole);

private slots:
	void on_lose_client_BTN_clicked();
	void on_undo_client_BTN_clicked();
	void on_send_client_BTN_clicked();
	void on_quit_client_BTN_clicked();
	void on_gameReady_client_BTN_clicked();

	//�ӷ������յ�����
	void getNewDataFromServer();
	//�Ӷ����Ƕ��������յ�����
	void getNewDataFromClient();

	//�յ��Է���ҵ���������
	void getNewConn();
	//�ͶԷ���ҽ������ӳɹ�
	void connSuccessful();
	//�ͶԷ���ҽ�������ʧ��
	void connFailed();

	//�Է���ʱ
	void timeout();

protected:
	//��Ӧ�ر��¼�
	void closeEvent(QCloseEvent *event);

	//�ػ��¼�
	void paintEvent(QPaintEvent *event);

	//��갴���¼�
	void mousePressEvent(QMouseEvent *);

private:
	//��ʼ������
	void dataInit();

	//���ó�ʱ��Ϣ�Ķ�ʱ��
	QTimer timer;

	//��¼��ǰ�������̵���Ϣ
	int chessboardRecord[19][19];

	//�ر���Ϣ�Ǵӷ����������ģ�
	bool closeByServer;

	//���ݰ��ṹ
	msg_request_struct* msg_req_struct;

	//��ǰ��ݣ�������
	playerRole plyRole;

	//��ǰ��Ϸ״̬
	playerStatus plyStatus;

	//��һ����˭��?
	playerRole whosTurn;

	//˫����ս�ɼ�
	int win, lose;

	//��¼��ǰ�Ѿ����µ�����
	QList<QPair<QPoint, enum playerRole> > pieceRecord;

	//����ֱ��
	static const int pieceSize;

	//��Ϸ�������  m x m
	static const int gameCellCount;
	//��Ԫ�����С
	static const int gameCellSize;

	//��ͼƫ���������������
	static const int paintOffset_W;
	static const int paintOffset_H;

	//���λ��ƫ���������������
	static const int mouseMoveOffset_W;
	static const int mouseMoveOffset_H;

	//����귶Χ��ƫ��
	static const int halfCellWidth;
	static const int frameWidth;

	//ÿ��������С����ĸ߿�
	static const int paneWidth;
	static const int paneHeight;

	//���ڽ���������
	QTcpSocket *tcpSocket_server;

	//�û����֮���໥����������˫��һ��ΪtpcServer��һ��ΪtcpSocket
	QTcpServer *tcpServer_player;
	QTcpSocket *tcpSocket_player;

	Ui::GameStatusClass ui;

	//��ʼ���ؼ�����
	void widgetInit();

	//�յ���Ϣ
	void recvMsg_quitGame();
	void recvMsg_gameStart();
	void recvMsg_gameOP();
	void recvMsg_lose();
	void recvMsg_gameOver();
	void recvMsg_chat();
	void recvMsg_undo();
	void recvMsg_undoYes();
	void recvMsg_undoNo();

	//�ж��Ƿ�ʤ��
	//�˸�����
	bool checkWin();
	bool checkWinLURD(int last_x, int last_y, int winColor);
	bool checkWinUD(int last_x, int last_y, int winColor);
	bool checkWinRULD(int last_x, int last_y, int winColor);
	bool checkWinRL(int last_x, int last_y, int winColor);

	//�������Χ�ķ���
	void drawMouseArea(QPainter* painter);
	//������
	void drawGrid(QPainter* painter);
	//������
	void drawPieceRecord(QPainter* painter);
};

#endif // GAMESTATUS_H
