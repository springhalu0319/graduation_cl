#include "gobang.h"
bool  WorB = true;
Gobang::Gobang(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(gobangWidth, gobangWidth);
	setWindowIcon(QIcon(":/gobang.ico"));
	//setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint);
}

void Gobang::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	static const QPoint points[4] = {QPoint(2, 2),QPoint(2, gobangWidth - 2),
										QPoint(gobangWidth - 2, gobangWidth - 2), QPoint(gobangWidth - 2, 2) };
	painter.setPen(QPen(Qt::red, 4));
	painter.drawPolyline(points, 4);
	painter.drawLine(points[0], points[3]);
	
	painter.setRenderHint(QPainter::Antialiasing, true);
	drawLine(&painter);
	drawEggs(eggs, &painter);
	drawEggFrame(&painter);

}
void Gobang::drawLine(QPainter *painter)
{
	for(int i = 1; i < gobangWidth; i++)
	{
		painter->setPen(QPen(Qt::blue,2));
		painter->drawLine(3,cubeWidth * i, gobangWidth - 3, cubeWidth * i);
		painter->drawLine(cubeWidth * i, 3, cubeWidth * i, gobangWidth - 3);
	}
}
void Gobang::drawEgg(QPoint pos, QPainter *painter,bool WorB)
{
	//QRadialGradient eggGradient(0,0,14,0,0);
	//eggGradient.setColorAt(0.0,WorB ? Qt::black : Qt::white );
	//eggGradient.setColorAt(0.5,Qt::gray);
	//eggGradient.setColorAt(1.0,WorB ? Qt::white : Qt::black);
	painter->setBrush(QBrush(WorB ? Qt::white : Qt::black,Qt::SolidPattern));
	//painter->setBrush(eggGradient);
	painter->setPen(Qt::black);
	painter->drawEllipse(pos.x() - eggWidth / 2, pos.y() - eggWidth / 2, eggWidth, eggWidth);
}
void Gobang::drawEggs(QList<QPoint> eggs, QPainter *painter) 
{
	QMutableListIterator<QPoint> i(eggs);
	bool WhiteOrBlack = true;
	while(i.hasNext())
	{
		if(WhiteOrBlack)	WhiteOrBlack = false;
		else		WhiteOrBlack = true;
		drawEgg(i.next(),painter,WhiteOrBlack);
	}
}
void Gobang::mousePressEvent(QMouseEvent *event)
{
	QPoint point = event->pos();
	int x = cubeWidth * qRound(float(point.x()) / cubeWidth);
	int y = cubeWidth * qRound(float(point.y()) / cubeWidth);
	point.setX(x);
	point.setY(y);
	getEgg(point);
	update();
	if(checkWin(WorB))
	{
		QMessageBox::about(this, "Result", WorB ? "White win.     ^__^" : "Black win.     ^__^");
		eggs.clear();
		WorB = true;
	}
}
void Gobang::drawEggFrame(QPainter *painter)
{
	QPoint point = mapFromGlobal(QCursor::pos());
	int x = cubeWidth * qRound(float(point.x()) / cubeWidth);
	int y = cubeWidth * qRound(float(point.y()) / cubeWidth);
	painter->setPen(QPen(Qt::green,1));
	painter->drawLine(x - halfCubeWidth, y - halfCubeWidth, x - frameWidth, y - halfCubeWidth);
	painter->drawLine(x - halfCubeWidth, y + halfCubeWidth, x - frameWidth, y + halfCubeWidth);
	painter->drawLine(x + frameWidth, y - halfCubeWidth, x + halfCubeWidth, y - halfCubeWidth);
	painter->drawLine(x + frameWidth, y + halfCubeWidth, x + halfCubeWidth, y + halfCubeWidth);
	painter->drawLine(x - halfCubeWidth, y - halfCubeWidth, x - halfCubeWidth, y - frameWidth);
	painter->drawLine(x - halfCubeWidth, y + frameWidth, x - halfCubeWidth, y + halfCubeWidth);
	painter->drawLine(x + halfCubeWidth, y - halfCubeWidth, x + halfCubeWidth, y - frameWidth);
	painter->drawLine(x + halfCubeWidth, y + frameWidth, x + halfCubeWidth, y + halfCubeWidth);
	update();
}
bool Gobang::checkWin(bool WorB)
{
	//QMutableListIterator<QPoint> i(eggs);
	QList<QPoint> toWinEggs;
	int i = WorB ? 1: 0,i2;
	for(; i < eggs.size(); i += 2)
		toWinEggs.append(eggs.at(i));
	QMutableListIterator<QPoint> j(toWinEggs),k(toWinEggs);
	int countH, countV, countS1, countS2;
	while(j.hasNext())
	{
		QPoint point = j.next(),point2;
		countH = countV = countS1 = countS2 = 1;
		k = toWinEggs;
		while(k.hasNext()){
			point2 = k.next();
			i = point.x() - point2.x();
			i2 = point.y() - point2.y();
			if( i == 0 && ( i2 == -cubeWidth || i2 == -cubeWidth * 2 ||
				i2 == -cubeWidth * 3 || i2 == -cubeWidth * 4))
				countV++;
			if( i2 == 0 && (i == -cubeWidth || i == -cubeWidth * 2 ||
				i == -cubeWidth * 3 || i == -cubeWidth * 4))
				countH++;
			if( i2 == -cubeWidth && i == i2 || i2 == -cubeWidth * 2 && i == i2 ||
				i2 == -cubeWidth * 3 && i == i2 || i2 == -cubeWidth * 4 && i == i2)
				countS1++;
			if( i2 == -cubeWidth && i == -i2|| i2 == -cubeWidth * 2 && i == -i2 ||
				i2 == -cubeWidth * 3 && i == -i2 || i2 == -cubeWidth * 4 && i == -i2)
				countS2++;
			if(countH >= 5 || countV >= 5 || countS1 >= 5 || countS2 >= 5)	return true;
		}
		
	}
	return false;
}
void Gobang::getEgg(QPoint point)
{
	QMutableListIterator<QPoint> i(eggs);
	while(i.hasNext())
		if(i.next() == point)	return;
	eggs.append(point);
	if(WorB)	WorB = false;
	else		WorB = true;
}
	