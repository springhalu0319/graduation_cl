#include "datadisposalthread.h"

DataDisposalThread::DataDisposalThread(QObject *parent)
	: QThread(parent), msg_req_struct(NULL), tcpSocket_player(NULL)
{

}

DataDisposalThread::~DataDisposalThread()
{

}

void DataDisposalThread::setPara(QTcpSocket* _tcpSocket_player)
{
	tcpSocket_player = _tcpSocket_player;
}

void DataDisposalThread::run()
{
	QDataStream in;
	msg_req_struct = new msg_request_struct();
	in.setDevice(tcpSocket_player);
	in >> msg_req_struct->request >> msg_req_struct->data;
// 	int pos = msg_req_struct->data.indexOf("+");
// 	QString nickName = msg_req_struct->data.mid(0,pos);
// 	msg_req_struct->data = msg_req_struct->data.mid(pos+1,msg_req_struct->data.size() - pos - 1);
// 
// 	QString clientAddr = nickName + "(" + tcpSocket_player->peerAddress().toString() + ")";
	QString clientAddr = tcpSocket_player->peerAddress().toString();
	switch (msg_req_struct->request)
	{
	case COMM_CLIENT_DISCONN:
		DataClass::curConnCount--;
		emit updateCurConnCount();
		tcpSocket_player->close();
		tcpSocket_player = NULL;
		break;
	case COMM_CLIENT_CREATE:
		emit createRoom(clientAddr);
		break;
	case COMM_CLIENT_JOIN:
		emit joinRoom(msg_req_struct->data, clientAddr);
		break;
	case COMM_CLIENT_QUITGAME:
		emit quitRoom(msg_req_struct->data, clientAddr);
		break;
	default:
		break;
	}

	delete msg_req_struct;
	msg_req_struct = NULL;
}