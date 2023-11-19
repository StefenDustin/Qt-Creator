#include "stokbarang.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StokBarang w;
    w.show();
    return a.exec();
}
