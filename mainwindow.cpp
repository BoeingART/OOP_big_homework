
#include "mainwindow.h"

#include <iostream>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(480, 600);
    backgroundSetting();//设置背景
    menuBarSetting();//设置菜单栏（在左上方）
    toolBarSetting();//设置工具栏（在左侧，后可删去）
    statusBarSetting();//设置状态栏（在左下方，后可删去）
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
    QPixmap pixmap(testPic);
    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap.scaled(QSize(geometry().width(), geometry().height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    label->resize(QSize(geometry().width(), geometry().height()));
    //label->lower();
    this->setMinimumSize(width_of_window, height_of_window);
    this->setMaximumSize(width_of_window, height_of_window);
}

