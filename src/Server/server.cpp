#include "server.h"

Server::Server(QWidget *parent, Qt::WFlags flags) 
					 : QMainWindow(parent, flags), tcpServer_player(NULL), serverStatus(NULL)
{
	ui.setupUi(this);

	widgetInit();
}

Server::~Server()
{

}

void Server::widgetInit()
{
	ui.connPort_server_LE->setValidator(new QRegExpValidator(DataClass::regPort, this));
	ui.connLimit_server_LE->setValidator(new QRegExpValidator(DataClass::regConnLimit, this));
}

void Server::on_startServer_server_BTN_clicked()
{
	if(ui.connPort_server_LE->text() == "" || ui.connLimit_server_LE->text() == "")
	{
		QMessageBox::information(this,"错误","请先输入相关信息！");
		return ;
	}

	tcpServer_player = new QTcpServer(this);
	if(!(tcpServer_player->listen(QHostAddress::Any, ui.connPort_server_LE->text().toInt())))
	{
		QMessageBox::information(this,"错误","服务器监听端口失败！");
		return ;
	}

	DataClass::maxConnectionLimit = ui.connLimit_server_LE->text().toInt();
	DataClass::connPort = ui.connPort_server_LE->text().toInt();
	serverStatus = new ServerStatus();
	serverStatus->setPara(tcpServer_player);
	//接受到新的连接
	connect(tcpServer_player, SIGNAL(newConnection()), serverStatus, SLOT(getNewConn()));
	connect(serverStatus, SIGNAL(stopService()), this, SLOT(stopService()));
	serverStatus->show();
	this->hide();
}

void Server::stopService()
{
	DataClass::curConnCount = 0;
	if(serverStatus)
	{
		delete serverStatus;
		serverStatus = NULL;
	}
	this->show();
}