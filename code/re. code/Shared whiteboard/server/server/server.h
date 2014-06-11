#ifndef SERVER_H
#define SERVER_H

#include <QHostInfo>
#include <QCloseEvent>
#include <QMessageBox>
#include <QtGui/QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include "ui_server.h"
#include "dataStruct.h"

class server : public QMainWindow
{
	Q_OBJECT

public:
	server(QWidget *parent = 0, Qt::WFlags flags = 0);
	~server();

private slots:
	void on_startServer_clicked();
	void on_stopServer_clicked();

	void getData();
	void newConnectionSlot();

protected:
	void closeEvent(QCloseEvent *event);

private:
	QTcpServer *tcpServer;
	QTcpSocket *tcpSocket;

	messageStruct message;

	Ui::serverClass ui;
};

#endif // SERVER_H
