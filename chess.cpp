#include "chess.h"
#include <iostream>

using namespace std;

chess::chess(QWidget *parent):
    QPushButton(parent)
{
    std::cout << "create a chess" << std::endl;
}

void chess::keyPressEvent(QKeyEvent *event){
    //if(event->modifiers()==Qt::ControlModifier)   //如果按下了Ctrl键
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


