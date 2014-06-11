#include "client.h"

#include <QTextCodec>
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
        QTextCodec *codec = QTextCodec::codecForName("gbk");
	QTextCodec::setCodecForLocale(codec); 
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	QApplication a(argc, argv);
	a.setFont(QFont("simsun", 10, QFont::Normal));

	Client w;
	w.show();
	return a.exec();
}
