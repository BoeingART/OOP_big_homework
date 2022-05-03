#include "mainwindow.h"

#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout << 123 << endl;
    MainWindow gameStarter;
    gameStarter.setWindowTitle("华容道");
    gameStarter.show();

    return a.exec();
}
