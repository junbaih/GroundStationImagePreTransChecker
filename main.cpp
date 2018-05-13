#include "ImgWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImgWidget w;
	w.show();
	return a.exec();
}
