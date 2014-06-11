#include "server.h"

server::server(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	tcpServer = NULL;

	//获取本机IP
	QString hostIp;
	QString localHostName = QHostInfo::localHostName();
	QHostInfo info = QHostInfo::fromName(localHostName);
	foreach(QHostAddress address,info.addresses())
	{
		if(address.protocol() == QAbstractSocket::IPv4Protocol) 
		{
			hostIp = address.toString();
			break;
		}
	}
	//用正则表达式分析IP
	QRegExp regExp("(\\d+).(\\d+).(\\d+).(\\d+)");
	regExp.setMinimal(false);
	regExp.indexIn(hostIp);
	for(int i=0; i<4; i++)
		message.messageHeader.srcIP[i] = (unsigned char)(regExp.cap(i + 1).toInt());
}

server::~server()
{

}

void server::on_startServer_clicked()
{
	tcpServer = new QTcpServer(this);
	tcpServer->listen(QHostAddress::Any, 11694);
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));		//有新的连接
	ui.startServer->setDisabled(true);
	ui.stopServer->setDisabled(false);
}
void server::on_stopServer_clicked()
{
	tcpServer->close();
	ui.startServer->setDisabled(false);
	ui.stopServer->setDisabled(true);

	QList<QTcpSocket *> allTcpSocket = tcpServer->findChildren<QTcpSocket *>();
	for(int i=0; i<allTcpSocket.size(); i++)
	{
		QDataStream out;
		out.setDevice(allTcpSocket[i]);
		out   << disconn << message.messageHeader.srcIP[0] << message.messageHeader.srcIP[1] 
		<< message.messageHeader.srcIP[2] << message.messageHeader.srcIP[3];
	}
	ui.userList->clear();
}

void server::getData()
{
	int mark;

	QDataStream in;
	QList<QTcpSocket *> allTcpSocket = tcpServer->findChildren<QTcpSocket *>();
	for(int i=0; i<allTcpSocket.size(); i++)
	{
		in.setDevice(allTcpSocket[i]);
		in >> mark >> message.messageHeader.desIP[0] >> message.messageHeader.desIP[1] 
			>> message.messageHeader.desIP[2] >> message.messageHeader.desIP[3];
		
		if(!mark && message.messageHeader.desIP[0] == 0 && message.messageHeader.desIP[1] == 0)
			continue;
		break;
	}
	
	QString userIp = QString("%1.%2.%3.%4").arg(message.messageHeader.desIP[0]).arg(message.messageHeader.desIP[1])
		.arg(message.messageHeader.desIP[2]).arg(message.messageHeader.desIP[3]);
	if(painted == mark)
	{
		in >> message.userOpInfo.opKind	>> message.userOpInfo.startPoint.x 
			>> message.userOpInfo.startPoint.y >> message.userOpInfo.endPoint.x 
			>> message.userOpInfo.endPoint.y;

		QString op;
		switch (message.userOpInfo.opKind)
		{
		case line :
			op = "直线";
			break;
		case circle :
			op = "圆";
			break ;
		case rectangle :
			op = "矩形";
			break ;
		case ellipse :
			op = "椭圆";
			break;
		default :
			break;
		}
		ui.userOP->append( QString("用户：%1 画了一个：%2 起始坐标为:(%3,%4)，终点坐标为:(%5,%6)")
											.arg(userIp).arg(op).arg(message.userOpInfo.startPoint.x).arg(message.userOpInfo.startPoint.y)
											.arg(message.userOpInfo.endPoint.x).arg(message.userOpInfo.endPoint.y));

		//用于获取当前所有连接到QTcpServer的QTcpSocket
		QList<QTcpSocket *> allTcpSocket = tcpServer->findChildren<QTcpSocket *>();
		for(int i=0; i<allTcpSocket.size(); i++)
		{
			QDataStream out;
			out.setDevice(allTcpSocket[i]);
			out   << painted << message.messageHeader.srcIP[0] << message.messageHeader.srcIP[1] 
					<< message.messageHeader.srcIP[2] << message.messageHeader.srcIP[3] 
					<< message.userOpInfo.opKind << message.userOpInfo.startPoint.x 
					<< message.userOpInfo.startPoint.y << message.userOpInfo.endPoint.x 
					<< message.userOpInfo.endPoint.y;
		}

	}
	else if(conn == mark)
	{
		ui.userOP->append(QString("%1 加入").arg(userIp));
		ui.userList->addItem(userIp);
	}
	else if(disconn == mark)
	{
		ui.userOP->append(QString("%1 退出").arg(userIp));
		
		for(int i=0; i<ui.userList->count(); i++)
		{
			if(ui.userList->item(i)->text() == userIp)
			{
				ui.userList->takeItem(i);
				break;
			}
		}
	}
}

void server::closeEvent(QCloseEvent *event)
{
	if(tcpServer)
 		tcpServer->close();

	event->accept();
}
void server::newConnectionSlot()
{
	tcpSocket = tcpServer->nextPendingConnection();
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getData()));									//发送数据过来时
}
