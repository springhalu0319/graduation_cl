#ifndef CLIENT_H
#define CLIENT_H

#include <cmath>
#include <QEvent>
#include <QPainter>
#include <QRegExp>
#include <QHostInfo>
#include <QCloseEvent>
#include <QMessageBox>
#include <QtGui/QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include "ui_client.h"
#include "dataStruct.h"

class client : public QMainWindow
{
	Q_OBJECT

public:
	client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~client();

private slots:
	void on_login_clicked();
	void on_logout_clicked();

	void error();
	void getData();
	void sendRequest();
	void connectionClosedByServer();

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	QTcpSocket *tcpSocket;

	messageStruct message;

	Ui::clientClass ui;
};

#endif // CLIENT_H
