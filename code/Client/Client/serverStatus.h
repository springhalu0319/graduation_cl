#ifndef SERVERSTATUS_H
#define SERVERSTATUS_H

#include <QtGui/QMainWindow>

#include "dataClass.h"
#include "gameStatus.h"
#include "ui_serverStatus.h"

class ServerStatus : public QDialog
{
	Q_OBJECT

public:
	ServerStatus(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ServerStatus();

	//���ò���
	void setPara(QTcpSocket *_tcpSocket_server);
	//�����ǳ�
	void setNickName(QString);

	//�������ر�����
	void connClosedByServer();

private slots:
	//˫�����˵���������
	void on_clientStatus_client_TBW_itemDoubleClicked(QTableWidgetItem*);

	//�յ�������
	void getNewData();

	void on_quit_client_BTN_clicked();
	void on_create_client_BTN_clicked();

signals:
	void disconnection();

protected:
	//��Ӧ�ر��¼�
	void closeEvent(QCloseEvent *);

private:
	Ui::ServerStatusClass ui;

	//��Ϸ����
	GameStatus gameStatus;

	//������Ҷ�ս״̬
	QList<QPair<QString, QString> >playerFightInfo;

	//���ݰ�����
	msg_request_struct* msg_req_struct;

	//���ڽ���������
	QTcpSocket *tcpSocket_server;

	//������Ϸ������Ϣ
	void setGameInfo(QString& data);
};

#endif // SERVERSTATUS_H
