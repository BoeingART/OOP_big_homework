#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<cstring>
#include<string>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    core = new chessMain();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionstart_triggered()
{
    QWidget* widget = this->findChild<QWidget*>("widget");
    QPushButton* zhangfei = widget->findChild<QPushButton*>("Zhangfei");
    zhangfei->setGeometry(0, 0, 100, 200);
    QPushButton* caocao = widget->findChild<QPushButton*>("Caocao");
    caocao->setGeometry(100, 0, 200, 200);
    QPushButton* machao = widget->findChild<QPushButton*>("Machao");
    machao->setGeometry(300, 0, 100, 200);
    QPushButton* huangzhong = widget->findChild<QPushButton*>("Huangzhong");
    huangzhong->setGeometry(0, 200, 100, 200);
    QPushButton* zhaoyun = widget->findChild<QPushButton*>("Zhaoyun");
    zhaoyun->setGeometry(300, 200, 100, 200);
    QPushButton* guanyu = widget->findChild<QPushButton*>("Guanyu");
    guanyu->setGeometry(100, 300, 200, 100);
    QPushButton* infantry_1 = widget->findChild<QPushButton*>("Infantry_1");
    infantry_1->setGeometry(0, 400, 100, 100);
    QPushButton* infantry_2 = widget->findChild<QPushButton*>("Infantry_2");
    infantry_2->setGeometry(100, 400, 100, 100);
    QPushButton* infantry_3 = widget->findChild<QPushButton*>("Infantry_3");
    infantry_3->setGeometry(200, 400, 100, 100);
    QPushButton* infantry_4 = widget->findChild<QPushButton*>("Infantry_4");
    infantry_4->setGeometry(300, 400, 100, 100);
    core->chessReset();
}

void MainWindow::on_Guanyu_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Guanyu");
    widget->setFocus();
}


void MainWindow::on_Caocao_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Caocao");
    widget->setFocus();
}


void MainWindow::on_Zhangfei_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Zhangfei");
    widget->setFocus();
}


void MainWindow::on_Machao_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Machao");
    widget->setFocus();
}



void MainWindow::on_Huangzhong_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Huangzhong");
    widget->setFocus();
}


void MainWindow::on_Zhaoyun_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Zhaoyun");
    widget->setFocus();
}



void MainWindow::on_Infantry_1_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Infantry_1");
    widget->setFocus();
}


void MainWindow::on_Infantry_2_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Infantry_2");
    widget->setFocus();
}



void MainWindow::on_Infantry_3_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Infantry_3");
    widget->setFocus();
}


void MainWindow::on_Infantry_4_clicked()
{
    QWidget* widget = (QWidget*)(findChild<QWidget*>("widget"));
    widget->setProperty("focusx", "Infantry_4");
    widget->setFocus();
}

void MainWindow::keyPressEvent(QKeyEvent *ev){
    QWidget* widget = this->findChild<QWidget*>("widget");
    if((widget->property("focusx").toString()) == "Caocao"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("cc", 'u')){
                QPushButton* caocao = widget->findChild<QPushButton*>("Caocao");
                caocao->setGeometry(caocao->x(), caocao->y() - 100, 200, 200);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("cc", 'l')){
                QPushButton* caocao = widget->findChild<QPushButton*>("Caocao");
                caocao->setGeometry(caocao->x() - 100, caocao->y(), 200, 200);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("cc", 'd')){
                QPushButton* caocao = widget->findChild<QPushButton*>("Caocao");
                caocao->setGeometry(caocao->x(), caocao->y() + 100, 200, 200);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("cc", 'r')){
                QPushButton* caocao = widget->findChild<QPushButton*>("Caocao");
                caocao->setGeometry(caocao->x() + 100, caocao->y(), 200, 200);
                return;
            }
        }
    if((widget->property("focusx").toString()) == "Guanyu"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("g", 'u')){
                QPushButton* guanyu = widget->findChild<QPushButton*>("Guanyu");
                guanyu->setGeometry(guanyu->x(), guanyu->y() - 100, 200, 100);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("g", 'l')){
                QPushButton* guanyu = widget->findChild<QPushButton*>("Guanyu");
                guanyu->setGeometry(guanyu->x() - 100, guanyu->y(), 200, 100);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("g", 'd')){
                QPushButton* guanyu = widget->findChild<QPushButton*>("Guanyu");
                guanyu->setGeometry(guanyu->x(), guanyu->y() + 100, 200, 100);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("g", 'r')){
                QPushButton* guanyu = widget->findChild<QPushButton*>("Guanyu");
                guanyu->setGeometry(guanyu->x() + 100, guanyu->y(), 200, 100);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Zhangfei"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("f", 'u')){
                QPushButton* zhangfei = widget->findChild<QPushButton*>("Zhangfei");
                zhangfei->setGeometry(zhangfei->x(), zhangfei->y() - 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("f", 'l')){
                QPushButton* zhangfei = widget->findChild<QPushButton*>("Zhangfei");
                zhangfei->setGeometry(zhangfei->x() - 100, zhangfei->y(), 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("f", 'd')){
                QPushButton* zhangfei = widget->findChild<QPushButton*>("Zhangfei");
                zhangfei->setGeometry(zhangfei->x(), zhangfei->y() + 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("f", 'r')){
                QPushButton* zhangfei = widget->findChild<QPushButton*>("Zhangfei");
                zhangfei->setGeometry(zhangfei->x() + 100, zhangfei->y(), 100, 200);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Machao"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("m", 'u')){
                QPushButton* machao = widget->findChild<QPushButton*>("Machao");
                machao->setGeometry(machao->x(), machao->y() - 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("m", 'l')){
                QPushButton* machao = widget->findChild<QPushButton*>("Machao");
                machao->setGeometry(machao->x() - 100, machao->y(), 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("m", 'd')){
                QPushButton* machao = widget->findChild<QPushButton*>("Machao");
                machao->setGeometry(machao->x(), machao->y() + 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("m", 'r')){
                QPushButton* machao = widget->findChild<QPushButton*>("Machao");
                machao->setGeometry(machao->x() + 100, machao->y(), 100, 200);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Huangzhong"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("h", 'u')){
                QPushButton* huangzhong = widget->findChild<QPushButton*>("Huangzhong");
                huangzhong->setGeometry(huangzhong->x(), huangzhong->y() - 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("h", 'l')){
                QPushButton* huangzhong = widget->findChild<QPushButton*>("Huangzhong");
                huangzhong->setGeometry(huangzhong->x() - 100, huangzhong->y(), 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("h", 'd')){
                QPushButton* huangzhong = widget->findChild<QPushButton*>("Huangzhong");
                huangzhong->setGeometry(huangzhong->x(), huangzhong->y() + 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("h", 'r')){
                QPushButton* huangzhong = widget->findChild<QPushButton*>("Huangzhong");
                huangzhong->setGeometry(huangzhong->x() + 100, huangzhong->y(), 100, 200);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Zhaoyun"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("y", 'u')){
                QPushButton* zhaoyun = widget->findChild<QPushButton*>("Zhaoyun");
                zhaoyun->setGeometry(zhaoyun->x(), zhaoyun->y() - 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("y", 'l')){
                QPushButton* zhaoyun = widget->findChild<QPushButton*>("Zhaoyun");
                zhaoyun->setGeometry(zhaoyun->x() - 100, zhaoyun->y(), 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("y", 'd')){
                QPushButton* zhaoyun = widget->findChild<QPushButton*>("Zhaoyun");
                zhaoyun->setGeometry(zhaoyun->x(), zhaoyun->y() + 100, 100, 200);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("y", 'r')){
                QPushButton* zhaoyun = widget->findChild<QPushButton*>("Zhaoyun");
                zhaoyun->setGeometry(zhaoyun->x() + 100, zhaoyun->y(), 100, 200);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Infantry_1"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("a", 'u')){
                QPushButton* infantry_1 = widget->findChild<QPushButton*>("Infantry_1");
                infantry_1->setGeometry(infantry_1->x(), infantry_1->y() - 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("a", 'l')){
                QPushButton* infantry_1 = widget->findChild<QPushButton*>("Infantry_1");
                infantry_1->setGeometry(infantry_1->x() - 100, infantry_1->y(), 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("a", 'd')){
                QPushButton* infantry_1 = widget->findChild<QPushButton*>("Infantry_1");
                infantry_1->setGeometry(infantry_1->x(), infantry_1->y() + 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("a", 'r')){
                QPushButton* infantry_1 = widget->findChild<QPushButton*>("Infantry_1");
                infantry_1->setGeometry(infantry_1->x() + 100, infantry_1->y(), 100, 100);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Infantry_2"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("b", 'u')){
                QPushButton* infantry_2 = widget->findChild<QPushButton*>("Infantry_2");
                infantry_2->setGeometry(infantry_2->x(), infantry_2->y() - 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("b", 'l')){
                QPushButton* infantry_2 = widget->findChild<QPushButton*>("Infantry_2");
                infantry_2->setGeometry(infantry_2->x() - 100, infantry_2->y(), 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("b", 'd')){
                QPushButton* infantry_2 = widget->findChild<QPushButton*>("Infantry_2");
                infantry_2->setGeometry(infantry_2->x(), infantry_2->y() + 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("b", 'r')){
                QPushButton* infantry_2 = widget->findChild<QPushButton*>("Infantry_2");
                infantry_2->setGeometry(infantry_2->x() + 100, infantry_2->y(), 100, 100);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Infantry_3"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("c", 'u')){
                QPushButton* infantry_3 = widget->findChild<QPushButton*>("Infantry_3");
                infantry_3->setGeometry(infantry_3->x(), infantry_3->y() - 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("c", 'l')){
                QPushButton* infantry_3 = widget->findChild<QPushButton*>("Infantry_3");
                infantry_3->setGeometry(infantry_3->x() - 100, infantry_3->y(), 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("c", 'd')){
                QPushButton* infantry_3 = widget->findChild<QPushButton*>("Infantry_3");
                infantry_3->setGeometry(infantry_3->x(), infantry_3->y() + 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("c", 'r')){
                QPushButton* infantry_3 = widget->findChild<QPushButton*>("Infantry_3");
                infantry_3->setGeometry(infantry_3->x() + 100, infantry_3->y(), 100, 100);
                return;
            }
    }
    if((widget->property("focusx").toString()) == "Infantry_4"){
        if(ev->key() == Qt::Key_W)
            if(core->chessMove("d", 'u')){
                QPushButton* infantry_4 = widget->findChild<QPushButton*>("Infantry_4");
                infantry_4->setGeometry(infantry_4->x(), infantry_4->y() - 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_A)
            if(core->chessMove("d", 'l')){
                QPushButton* infantry_4 = widget->findChild<QPushButton*>("Infantry_4");
                infantry_4->setGeometry(infantry_4->x() - 100, infantry_4->y(), 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_S)
            if(core->chessMove("d", 'd')){
                QPushButton* infantry_4 = widget->findChild<QPushButton*>("Infantry_4");
                infantry_4->setGeometry(infantry_4->x(), infantry_4->y() + 100, 100, 100);
                return;
            }
        if(ev->key() == Qt::Key_D)
            if(core->chessMove("d", 'r')){
                QPushButton* infantry_4 = widget->findChild<QPushButton*>("Infantry_4");
                infantry_4->setGeometry(infantry_4->x() + 100, infantry_4->y(), 100, 100);
                return;
            }
    }


}

