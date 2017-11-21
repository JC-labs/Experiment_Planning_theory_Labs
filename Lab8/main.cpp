#include "gui.h"
#include "gui2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gui w;
	gui2 w2;
	w.show();
	w2.show();
	return a.exec();
}
