#include "desktopmainwindow.h"
#include <QApplication>
//#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesktopMainWindow w;
//    qDebug() << "SQL Drivers: " << drivers;
    w.show();
    return a.exec();
}


