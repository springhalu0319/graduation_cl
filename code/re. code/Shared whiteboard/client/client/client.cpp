#include "client.h"

client::client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	tcpSocket = NULL;

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

client::~client()
{

}

void client::getData()
{
	int mark;
	QDataStream in(tcpSocket);
	in >> mark >> message.messageHeader.desIP[0] >> message.messageHeader.desIP[1] 
	>> message.messageHeader.desIP[2] >> message.messageHeader.desIP[3];

	QString userIp = QString("%1.%2.%3.%4").arg(message.messageHeader.desIP[0]).arg(message.messageHeader.desIP[1])
		.arg(message.messageHeader.desIP[2]).arg(message.messageHeader.desIP[3]);
	if(painted == mark)
	{
		in >> message.userOpInfo.opKind	>> message.userOpInfo.startPoint.x 
			>> message.userOpInfo.startPoint.y >> message.userOpInfo.endPoint.x 
			>> message.userOpInfo.endPoint.y;
		update();
	}
	else if(disconn == mark)
	{
		QMessageBox::information(this,"提示","服务端退出");
		tcpSocket->close();
	}
}
void client::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing,true);
	painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
	
	Point start = message.userOpInfo.startPoint;
	Point end = message.userOpInfo.endPoint;
	switch (message.userOpInfo.opKind)
	{
	case line :
		{
			painter.drawLine(start.x, start.y, end.x, end.y);
			break;
		}
	case circle :
		{
			int r = sqrt( pow((float)(end.y - start.y), 2) + pow((float)(end.x - start.x), 2) );
			painter.drawEllipse(QPoint(start.x, start.y), r, r);
			break;
		}
	case rectangle :
		{
			painter.drawRect(start.x, start.y, end.x - start.x, end.y - start.y);
			break;
		}
	case ellipse :
		{
			QRectF rectangle(start.x, start.y, end.x - start.x, end.y - start.y);
			painter.drawEllipse(rectangle);
			break;
		}
	default :
		break ;
	}
}
void client::mousePressEvent(QMouseEvent *event)
{
	if(ui.line->isChecked())
		message.userOpInfo.opKind = line;
	else if(ui.circle->isChecked())
		message.userOpInfo.opKind = circle;
	else if(ui.rectangle->isChecked())
		message.userOpInfo.opKind = rectangle;
	else
		message.userOpInfo.opKind = ellipse;
	
	message.userOpInfo.startPoint.x = event->x();
	message.userOpInfo.startPoint.y = event->y();
}

void client::mouseMoveEvent(QMouseEvent *event)
{
	message.userOpInfo.endPoint.x = event->x();
	message.userOpInfo.endPoint.y = event->y();

	update();

}

void client::mouseReleaseEvent(QMouseEvent *event)
{
	message.userOpInfo.endPoint.x = event->x();
	message.userOpInfo.endPoint.y = event->y();
	if(message.userOpInfo.endPoint.x == message.userOpInfo.startPoint.x &&
		message.userOpInfo.endPoint.y == message.userOpInfo.startPoint.y)
		return ;

	update();
	if(!ui.login->isEnabled())
	{
		QDataStream out;
		out.setDevice(tcpSocket);
		out   << painted << message.messageHeader.srcIP[0] << message.messageHeader.srcIP[1] 
				<< message.messageHeader.srcIP[2] << message.messageHeader.srcIP[3] 
				<< message.userOpInfo.opKind << message.userOpInfo.startPoint.x 
				<< message.userOpInfo.startPoint.y << message.userOpInfo.endPoint.x 
				<< message.userOpInfo.endPoint.y;
	}
}

void client::on_login_clicked()
{		
	QRegExp regExp("(\\d+).(\\d+).(\\d+).(\\d+)");
	regExp.setMinimal(false);
	regExp.indexIn(ui.hostName->text());
	for(int i=0; i<4; i++)
		message.messageHeader.desIP[i] = (unsigned char)(regExp.cap(i + 1).toInt());

	tcpSocket = new QTcpSocket(this);
	tcpSocket->connectToHost(ui.hostName->text(),11694);
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getData()));											//发送数据过来时
	connect(tcpSocket,SIGNAL(connected()),this,SLOT(sendRequest()));										//新的连接到来时
	connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error()));					//连接出错
	connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(connectionClosedByServer()));
}

void client::on_logout_clicked()
{	
	QDataStream out;
	out.setDevice(tcpSocket);
	out   << disconn << message.messageHeader.srcIP[0] << message.messageHeader.srcIP[1] 
			<< message.messageHeader.srcIP[2] << message.messageHeader.srcIP[3] ;

	QCoreApplication::processEvents();
	tcpSocket->close();

	ui.hostName->setDisabled(false);		
	ui.login->setDisabled(false);
	ui.logout->setDisabled(true);
}

void client::sendRequest()
{
	QMessageBox::information(this,"提示","登录服务器成功！");
	ui.hostName->setDisabled(true);		
	ui.login->setDisabled(true);
	ui.logout->setDisabled(false);
	QDataStream out;
	out.setDevice(tcpSocket);
	out   << conn << message.messageHeader.srcIP[0] << message.messageHeader.srcIP[1] 
			<< message.messageHeader.srcIP[2] << message.messageHeader.srcIP[3] ;
	disconnect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error()));		//连接出错
}

void client::connectionClosedByServer()
{
	QMessageBox::information(this,"提示","连接中断！");
	ui.groupBox_conn->setDisabled(false);

	ui.hostName->setDisabled(false);		
	ui.login->setDisabled(false);
	ui.logout->setDisabled(true);
}

void client::error()
{
	QMessageBox::information(this,"提示","连接中断！");
	ui.groupBox_conn->setDisabled(false);

	ui.hostName->setDisabled(false);		
	ui.login->setDisabled(false);
	ui.logout->setDisabled(true);
}

void client::closeEvent(QCloseEvent *event)
{
	if(tcpSocket)
	{
		QDataStream out;
		out.setDevice(tcpSocket);
		out   << disconn << message.messageHeader.srcIP[0] << message.messageHeader.srcIP[1] 
				<< message.messageHeader.srcIP[2] << message.messageHeader.srcIP[3] ;
		
		QCoreApplication::processEvents();
		tcpSocket->close();
	}

	event->accept();
}