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
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QAbstractButton>
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const QSize getbuttonSize(){
        return button;
    }

    void showAbout();

    QPushButton *start_game;
    QPushButton *about_game;
    QPushButton *exit_game;

private:
    Ui::MainWindow *ui;

    const QSize window {300,500};
    const QSize button {100,100};

    void menuBarSetting();
    void toolBarSetting();
    void statusBarSetting();
    void mainwindowSetting();
    void backgroundSetting();
    void widgetSetting();


    void closeEvent(QCloseEvent *event);

};

/*
class QPushButtonFixedSize: public QPushButton
{
public:
    QPushButtonFixedSize(*QWidget test): QPushButton(*QWidget test){

    }
    const QSize sizeHint();
};
*/

#endif // MAINWINDOW_H
