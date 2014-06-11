#ifndef SERVER_H
#define SERVER_H

#include "ui_server.h"
#include "dataClass.h"
#include "serverStatus.h"

class Server : public QMainWindow
{
	Q_OBJECT

public:
	Server(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Server();

private slots:
	void on_startServer_server_BTN_clicked();

	//�رշ���
	void stopService();

private:
	Ui::ServerClass ui;
	//TCPServer ����client������
	QTcpServer *tcpServer_player;

	//������״̬����
	ServerStatus *serverStatus;


	//��ʼ���ؼ�����
	void widgetInit();
};

#endif // SERVER_H
