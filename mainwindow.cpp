
#include "mainwindow.h"


#include <iostream>
#include <QLabel>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("华容道-开始游戏");
    this->resize(window);
    backgroundSetting();//设置背景
    //menuBarSetting();//设置菜单栏（在左上方）
    //toolBarSetting();//设置工具栏（在左侧，后可删去）
    //statusBarSetting();//设置状态栏（在左下方，后可删去）
    widgetSetting();//设置按钮选项

    gamewindowSetting();
    //MainwindowClose mainwindowExitRemainder;
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
    QWidget *button_widget = new QWidget(this);
    button_widget->setGeometry(0,0,300,500);
    /*
    QPushButtonFixedSize *start_game = new QPushButtonFixedSize(button_widget);
    QPushButtonFixedSize *exit_game = new QPushButtonFixedSize(button_widget);
    */
    start_game = new QPushButton(button_widget);
    about_game = new QPushButton(button_widget);
    exit_game = new QPushButton(button_widget);
    //std::cout << start_game->sizeHint().height() << std::endl;
    //start_game->setFixedSize(button);
    start_game->setGeometry({100,100,100,50});
    start_game->setText("开始游戏");
    about_game->setGeometry({100,225,100,50});
    about_game->setText("关于游戏");
    exit_game->setGeometry({100,350,100,50});
    exit_game->setText("退出游戏");

    QObject::connect(this->about_game, &QPushButton::clicked, this, &MainWindow::showAbout);
    QObject::connect(this->exit_game, &QPushButton::clicked, this, &MainWindow::close);
}

void MainWindow::gamewindowSetting(){
    gameWindow *gamer = new gameWindow;
    gamer->setWindowTitle("华容道");
    gamer->setWindowModality(Qt::ApplicationModal);//设置了当gamer打开后主窗体不可移动
    QObject::connect(this->start_game, &QPushButton::clicked, gamer, &gameWindow::show);

    std::cout << "connect second window" << std::endl;
}

void MainWindow::closeEvent(QCloseEvent *event){
    int choose;
    choose = QMessageBox::question(this, tr("退出游戏"),
                                   QString(tr("确认退出游戏?")),
                                   QMessageBox::Yes | QMessageBox::No);

    if (choose == QMessageBox::No){
          event->ignore();
    }
    else if (choose == QMessageBox::Yes){
          event->accept();
    }
}

void MainWindow::showAbout(){
    QMessageBox About(this);
    About.about(this, "关于游戏", "本游戏由栗嘉伟和谭臻至开发");
}

