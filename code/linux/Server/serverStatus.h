#ifndef SERVERSTATUS_H
#define SERVERSTATUS_H

#include <QtGui/QMainWindow>

#include "dataClass.h"
#include "ui_serverStatus.h"
#include "datadisposalthread.h"

class ServerStatus : public QDialog
{
	Q_OBJECT

public:
	ServerStatus(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ServerStatus();

	//传入参数
	void setPara(QTcpServer *_tcpServer_player);

protected:
	//响应关闭事件
	void closeEvent(QCloseEvent *event);

private slots:
	void on_closeServer_server_BTN_clicked();

	//收到新连接
	void getNewConn();

	//更新当前在线玩家
	void updateCurConnCount();
	//客户端请求创建主机
	void createRoom(QString);
	//客户端退出主机
	void quitRoom(QString, QString);
	//客户端加入主机
	void joinRoom(QString, QString);

signals:
	void stopService();

private:

	//数据结构
	msg_request_struct* msg_req_struct;

	//保存玩家对战状态
	QList<QPair<QString, QString> >playerFightInfo;

	//TCPServer 接受client的请求
	QTcpServer *tcpServer_player;

	Ui::ServerStatusClass ui;

	//初始化控件属性
	void widgetInit();

	//发送大厅信息
	void sendGameInfo(QTcpSocket* tcpSocket);

	//更新大厅信息
	void updateGameInfo();
};

#endif // SERVERSTATUS_H
