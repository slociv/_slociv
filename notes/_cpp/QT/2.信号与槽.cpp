
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *button = new QPushButton("quit");
    QObject::connect(button,SIGNAL(clicked()),&app,SLOT(quit()));
    button->show();
    return app.exec();
}
//信号就是事件，槽就是触发的函数