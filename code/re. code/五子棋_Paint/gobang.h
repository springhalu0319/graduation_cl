#ifndef GOBANG_H
#define GOBANG_H

#include <QtGui>


class Gobang : public QWidget
{
	Q_OBJECT

public:
	Gobang(QWidget *parent = 0);
	//~Gobang();
	void drawLine(QPainter *painter);
	void paintEvent(QPaintEvent *event);

	void drawEgg(QPoint pos, QPainter *painter, bool WorB);
	void drawEggs(QList<QPoint> eggs, QPainter *painter);
	void Gobang::drawEggFrame(QPainter *painter);
	void getEgg(QPoint point);

	void mousePressEvent(QMouseEvent *event);
	bool checkWin(bool WorB);
private:
	QList<QPoint> eggs;
};
const int cubePerLine = 18;
const int cubeWidth = 30;
const int eggWidth = 24;
const int gobangWidth = cubePerLine * cubeWidth; 
const int halfCubeWidth = 2 * cubeWidth / 3;
const int frameWidth = cubeWidth / 6;


#endif // GOBANG_H
