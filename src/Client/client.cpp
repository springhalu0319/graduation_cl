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
		QMessageBox::information(this,"����","�������������Ϣ��");
		return ;
	}

	tcpSocket_server = new QTcpSocket(this);
	tcpSocket_server->connectToHost(ui.serverAddr_client_LE->text(),ui.serverPort_client_LE->text().toInt());
	//���ӳɹ�
	connect(tcpSocket_server,SIGNAL(connected()),this,SLOT(connSuccessful()));
	//���ӳ���
	connect(tcpSocket_server,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(connFailed()));
}

void Client::connSuccessful()
{
	this->hide();

	DataClass::nickName = ui.nickName_client_LE->text();
	DataClass::connPort = ui.serverPort_client_LE->text().toInt();
	//���ò���
	serverStatus.setPara(tcpSocket_server);
	//�����Ͽ�����
	connect(&serverStatus, SIGNAL(disconnection()), this, SLOT(disconnection()));
	//���ܵ������ݹ���
	connect(tcpSocket_server, SIGNAL(readyRead()), &serverStatus, SLOT(getNewData()));
	serverStatus.show();
	return ;
}

void Client::connFailed()
{
	serverStatus.connClosedByServer();
	serverStatus.hide();
	this->show();
	QMessageBox::information(this,"����","���Ӷ�ʧ��\n"
		"���ܵ�ԭ��\n"
		"1.��������ַ��˿ڴ���\n"
		"2.�������ﵽ�������ޣ�\n"
		"3.�������رգ�");
	return ;
}

void Client::disconnection()
{
	serverStatus.hide();
	this->show();
	return ;
}