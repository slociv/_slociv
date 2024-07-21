//#include "mainwindow.h"
//#include <QLabel>
//
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("<h2><i>hello</i>"
                               "<font color=red>qt</font></h2>");
    label->show();
    //MainWindow w;
    //w.show();
    return app.exec();
}
