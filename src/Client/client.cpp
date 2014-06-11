#include "client.h"

Client::Client(QWidget *parent, Qt::WFlags flags)
					: QMainWindow(parent, flags), serverStatus(NULL), tcpSocket_server(NULL)
{
	ui.setupUi(this);

	widgetInit();
}

Client::~Client()
{

}

void Client::widgetInit()
{
	ui.serverAddr_client_LE->setValidator(new QRegExpValidator(DataClass::regIP, this));
	ui.serverPort_client_LE->setValidator(new QRegExpValidator(DataClass::regPort, this));
}

void Client::on_conn_client_BTN_clicked()
{
	if(ui.nickName_client_LE->text() == "" || ui.serverAddr_client_LE->text() == "" || ui.serverPort_client_LE->text() == "")
	{
		QMessageBox::information(this,"错误","请先输入相关信息！");
		return ;
	}

	tcpSocket_server = new QTcpSocket(this);
	tcpSocket_server->connectToHost(ui.serverAddr_client_LE->text(),ui.serverPort_client_LE->text().toInt());
	//连接成功
	connect(tcpSocket_server,SIGNAL(connected()),this,SLOT(connSuccessful()));
	//连接出错
	connect(tcpSocket_server,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(connFailed()));
}

void Client::connSuccessful()
{
	this->hide();

	DataClass::nickName = ui.nickName_client_LE->text();
	DataClass::connPort = ui.serverPort_client_LE->text().toInt();
	//设置参数
	serverStatus.setPara(tcpSocket_server);
	//主动断开连接
	connect(&serverStatus, SIGNAL(disconnection()), this, SLOT(disconnection()));
	//接受到新数据过来
	connect(tcpSocket_server, SIGNAL(readyRead()), &serverStatus, SLOT(getNewData()));
	serverStatus.show();
	return ;
}

void Client::connFailed()
{
	serverStatus.connClosedByServer();
	serverStatus.hide();
	this->show();
	QMessageBox::information(this,"错误","连接丢失！\n"
		"可能的原因：\n"
		"1.服务器地址或端口错误！\n"
		"2.服务器达到连接上限！\n"
		"3.服务器关闭！");
	return ;
}

void Client::disconnection()
{
	serverStatus.hide();
	this->show();
	return ;
}