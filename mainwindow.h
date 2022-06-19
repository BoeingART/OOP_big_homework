#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Core/chessmain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionstart_triggered();

    void on_Guanyu_clicked();

    void on_Caocao_clicked();

    void on_Zhangfei_clicked();

    void on_Machao_clicked();

    void on_Huangzhong_clicked();

    void on_Zhaoyun_clicked();

    void on_Infantry_1_clicked();

    void on_Infantry_2_clicked();

    void on_Infantry_3_clicked();

    void on_Infantry_4_clicked();

private:
    Ui::MainWindow *ui;
    chessMain* core;
protected:
    virtual void keyPressEvent(QKeyEvent *ev);
};

#endif // MAINWINDOW_H


