#include "mainwindow.h"

#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout << 123 << endl;
    MainWindow w;
    w.show();
    //w.close();
    return a.exec();
}
