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

	//�������
	void setPara(QTcpSocket* tcpSocket_player);

signals:
	//���µ�ǰ������
	void updateCurConnCount();
	//�пͻ������󴴽�����
	void createRoom(QString);
	//�ͻ����˳�����
	void quitRoom(QString, QString);
	//�ͻ��˼�������
	void joinRoom(QString, QString);

protected:
	void run();

private:
	//TCPSocket ���ܵ���������Ϣ
	QTcpSocket *tcpSocket_player;

	//���ݰ�����
	msg_request_struct* msg_req_struct;
	
};

#endif // DATADISPOSALTHREAD_H