#ifndef DATACLASS_H
#define DATACLASS_H

#include <QCoreApplication>

#include <QTimer>
#include <QPainter>
#include <QRegExp>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCloseEvent>
#include <QMainWindow>
#include <QDataStream>
#include <QMessageBox>

enum playerRole
{
	//���ڼ�¼ĳ��������˭�µ�
	HOST,
	GUEST
};

enum playerStatus
{
	//��¼��ǰ��������Ϸ�����ڵȴ���Ϸ
	playingGame,
	readyToPlayingGame
};

enum comm_request_type
{
	//���ӷ�����ʧ��
	COMM_SERVER_CONN_FAILED,
	//���ӷ������ɹ�
	COMM_SERVER_CONN_SUCCESSFUL,
	//�������ر�
	COMM_SERVER_CLOSE,
	//���������ʹ�����Ϣ
	COMM_SERVER_GAMEINFO,

	//�˳���Ϸ
	COMM_CLIENT_QUITGAME,
	//����Ͽ�������
	COMM_CLIENT_DISCONN,
	//�ͻ����������ӷ�����
	COMM_CLIENT_CONN,
	//�ͻ������󴴽�����
	COMM_CLIENT_CREATE,
	//�ͻ������������Ϸ
	COMM_CLIENT_JOIN,
	//˫��׼����ϣ���Ϸ��ʼ
	COMM_CLIENT_GAMESTART,
	//ĳ�����ʤ������Ϸ����
	COMM_CLIENT_GAMEOVER,
	//�����Ϸ����������
	COMM_CLIENT_GAMEOP,
	//�����Ϸ����������������Ϣ
	COMM_CLIENT_CHAT,
	//�����Ϸ����������
	COMM_CLIENT_UNDO,
	//�����Ϸ����������ظ�yes
	COMM_CLIENT_UNDO_YES,
	//�����Ϸ����������ظ�no
	COMM_CLIENT_UNDO_NO,
	//�����Ϸ���������� 
	COMM_CLIENT_LOSE,
	//��ҷ�����Ϣ���Է�����
	COMM_CLIENT_LOSTCONN
};

struct msg_request_struct
{
	//��������
	qint8 request;
	//����
	QString data;
};

class DataClass
{
public:
	//����˽��ܵ����������
	static int maxConnectionLimit;

	//��ǰ������������
	static int curConnCount;

	//����ˣ��ͻ������Ӷ˿�
	static int connPort;

	//������ʽ���˿ڣ�IP������
	static const QRegExp regPort;
	static const QRegExp regIP;
	static const QRegExp regConnLimit;

	//ÿ��������С����ĸ߿�
	static const int paneWidth;
	static const int paneHeight;

	//ȷ�϶Ի���
	static bool checkDialog(QString title, QString context);

	//debug messagebox
	static void dbgBox(int lPara, int rPara);
	static void dbgBox(int lPara, QString rPara);
	static void dbgBox(QString lPara, QString rPara);

	//��������
	static void sendMsg(comm_request_type type, QString context, QTcpSocket* _tcpSocket);
};


#endif //DATACLASS_H