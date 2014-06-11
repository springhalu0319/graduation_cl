#include "gobang.h"
#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gobang w;
	w.show();
	return a.exec();
}
