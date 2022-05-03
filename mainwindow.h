#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define testPic "/Users/boeingart/OOP_big_homework/source/pictures/test.jpg"

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QKeySequence>
#include <QToolBar>
#include <QIcon>
#include <QStatusBar>
#include <QPaintEvent>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void menuBarSetting();
    void toolBarSetting();
    void statusBarSetting();
    void mainwindowSetting();
    void backgroundSetting();
};
#endif // MAINWINDOW_H
