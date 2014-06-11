#ifndef CLIENT_H
#define CLIENT_H

#include "ui_client.h"
#include "dataClass.h"
#include "serverStatus.h"

#include <QtGui/QMainWindow>

class Client : public QMainWindow
{
	Q_OBJECT

public:
	Client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Client();

private slots:
	void on_conn_client_BTN_clicked();

	//���ӷ������ɹ�
	void connSuccessful();
	//���ӷ�����ʧ�� 
	void connFailed();

	//�����Ͽ�����
	void disconnection();

private:
	Ui::ClientClass ui;
	//���ڽ���������
	QTcpSocket *tcpSocket_server;

	//������״̬���� 
	ServerStatus serverStatus;


	//��ʼ���ؼ�����
	void widgetInit();
};

#endif // CLIENT_H
