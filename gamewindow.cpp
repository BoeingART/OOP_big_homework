#include "gamewindow.h"
#include "chess.h"
#include <iostream>
using namespace std;

gameWindow::gameWindow(QWidget *parent):
    QMainWindow(parent)
{
    std::cout << "create gameWindow" << std::endl;

    this->setWindowModality(Qt::ApplicationModal);
    this->resize(window);
    this->setWindowTitle("华容道");
    setChessBoard();
    setChess();
}

void gameWindow::setChessBoard(){
    chessBoard = new QWidget;
    chessBoard->setParent(this);
    chessBoard->setGeometry(0,0,window_width, window_height / 5 * 4);
    //chessBoard->setStyleSheet("background-color:#37474F");
}

void gameWindow::setChess(){
    chess *Test = new chess;
    std::cout << "chess" << std::endl;
    Test->setParent(chessBoard);
    Test->setGeometry(10,10,50,50);
    Test->setText("测试移动");
    Test->show();
    QPushButton test1;
    test1.setGeometry(80,80,50,50);
    test1.show();
}
/*
void gameWindow::keyPressEvent(QKeyEvent *event){
    //if(event->modifiers()==Qt::ControlModifier)   //如果按下了Ctrl键
    if(event->key() == Qt::Key_K){
        cout << 123 << endl;
    }

    {
       if(event->key()==Qt::Key_Left){
            cout << "left" << endl;
           //startX=(startX-1<0)?startX:startX-1;//左移
       }
       if(event->key()==Qt::Key_Right){
           cout << "right" << endl;
          // startX=(startX+1+image.width()>w)?startX:startX+1;//右移
       }
       if(event->key()==Qt::Key_Up){
           //startY=(startY-1<0)?startY:startY-1;//上移
       }
       if(event->key()==Qt::Key_Down){
           //startY=(startY+1+image.height()>h)?startY:startY+1;//下移
       }

    }
}
*/
