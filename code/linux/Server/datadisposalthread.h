#ifndef DATADISPOSALTHREAD_H
#define DATADISPOSALTHREAD_H

#include <QThread>

#include "dataClass.h"

class DataDisposalThread : public QThread
{
	Q_OBJECT

public:
	DataDisposalThread(QObject *parent);
	~DataDisposalThread();

	//传入参数
	void setPara(QTcpSocket* tcpSocket_player);

signals:
	//更新当前连接数
	void updateCurConnCount();
	//有客户端请求创建主机
	void createRoom(QString);
	//客户端退出主机
	void quitRoom(QString, QString);
	//客户端加入主机
	void joinRoom(QString, QString);

protected:
	void run();

private:
	//TCPSocket 接受到了数据信息
	QTcpSocket *tcpSocket_player;

	//数据包申明
	msg_request_struct* msg_req_struct;
	
};

#endif // DATADISPOSALTHREAD_H
