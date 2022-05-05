#include "mainwindow.h"
#include "mainwindowclose.h"

#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //cout << 123 << endl;
    MainWindow gameStarter;
    gameStarter.setWindowTitle("华容道");

    QObject::connect(gameStarter.about_game, &QPushButton::clicked, &gameStarter, &MainWindow::showAbout);
    QObject::connect(gameStarter.exit_game, &QPushButton::clicked, &gameStarter, &MainWindow::close);
    gameStarter.show();

    return a.exec();
}

