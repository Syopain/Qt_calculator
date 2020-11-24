#include "calculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Calculator w;
    w.setWindowIcon(QIcon(":/image/Calculator.ico"));
	w.show();
	return a.exec();
}
