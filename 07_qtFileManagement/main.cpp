#include "mainwindow.h"  // write INI
#include "mainwindow2.h" // read INI
#include "mainwindow3.h" // Create XML
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow3 w;
    w.show();
    return a.exec();
}
