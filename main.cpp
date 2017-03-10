#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDesktopWidget wi;

    int screenWidth = wi.screen()->width();
    int screenHeight = wi.screen()->height();


    MainWindow *w = new MainWindow();
    int width = w->frameGeometry().width();
    int height = w->frameGeometry().height();

    w->setGeometry( (screenWidth/2)-(width/2), (screenHeight/2)-(height/2), width, height );
    w->setVisible(true);
    w->show();

    return a.exec();
}
