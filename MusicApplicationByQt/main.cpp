#include "MusicApplicationByQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	MusicApplicationByQt w;
	w.show();
	return a.exec();
	

}
