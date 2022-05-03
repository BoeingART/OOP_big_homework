
#include "mainwindow.h"


#include <iostream>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(window);
    backgroundSetting();//设置背景
    menuBarSetting();//设置菜单栏（在左上方）
    //toolBarSetting();//设置工具栏（在左侧，后可删去）
    //statusBarSetting();//设置状态栏（在左下方，后可删去）
    widgetSetting();//设置按钮选项
}


MainWindow::~MainWindow(){
    std::cout << "mainwindow is deleted" << std::endl;
}

void MainWindow::menuBarSetting(){
    QMenuBar * mainwindow_menu = this->menuBar();
    mainwindow_menu->setNativeMenuBar(false);
    QMenu *mainwindow_menu_settings = new QMenu("设置", mainwindow_menu);
    mainwindow_menu->addMenu(mainwindow_menu_settings);
    mainwindow_menu_settings->addAction("声音");
    //*QMenu::addSeparator();
    mainwindow_menu_settings->addAction("关于");
    QMenu *mainwindow_menu_control = new QMenu("控制", mainwindow_menu);
    mainwindow_menu->addMenu(mainwindow_menu_control);
    mainwindow_menu_control->addAction("退出", this, SLOT(close()), QKeySequence("Ctrl+E"));
}

void MainWindow::toolBarSetting(){
    this->addToolBar("工具栏");
    QToolBar *toolBar = new QToolBar("test", this);
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    //toolBar->addAction("close");
    toolBar->addAction(QIcon(testPic), "close", this, SLOT(close()));
    toolBar->addAction("close",this,SLOT(close()));
}

void MainWindow::statusBarSetting(){
    QStatusBar *mainwindow_status = this->statusBar();
    mainwindow_status->showMessage("欢迎进入游戏",1000);
}


void MainWindow::backgroundSetting(){
    QPixmap pixmap("/Users/boeingart/OOP_big_homework/source/pictures/background.png");
    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap.scaled(QSize(geometry().width(), geometry().height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    label->resize(QSize(geometry().width(), geometry().height()));
    //label->lower();
    this->setMinimumSize(window);
    this->setMaximumSize(window);
}

void MainWindow::widgetSetting(){
    QWidget *botton_widget = new QWidget(this);
    botton_widget->setGeometry(0,0,300,500);
    /*
    QPushButtonFixedSize *start_game = new QPushButtonFixedSize(botton_widget);
    QPushButtonFixedSize *exit_game = new QPushButtonFixedSize(botton_widget);
    */
    QPushButton *start_game = new QPushButton(botton_widget);
    QPushButton *exit_game = new QPushButton(botton_widget);
    //std::cout << start_game->sizeHint().height() << std::endl;
    //start_game->setFixedSize(botton);
    start_game->setGeometry({100,100,100,50});
    start_game->setText("开始游戏");
    //exit_game->setFixedSize(botton);
    exit_game->setGeometry({100,350,100,50});
    exit_game->setText("退出游戏");
    //QObject::connect(&exit_game,&clicked,&MainWindow,&close);
    //QVBoxLayout *mainwindow_layout = new QVBoxLayout(botton_widget);
    //mainwindow_layout->addWidget(start_game, Qt::AlignCenter);
    //mainwindow_layout->addWidget(exit_game, Qt::AlignCenter);
}

/*
const QSize QPushButtonFixedSize::sizeHint(){
    return {300,500}
}
*/
