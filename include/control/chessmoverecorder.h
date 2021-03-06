#ifndef CHESSMOVERECORDER_H
#define CHESSMOVERECORDER_H

#include "chesscontrol.h"

struct steps {
    char dir;
    char name;
    steps( char Name = '\0', char Dir = '\0' )
        : name( Name )
        , dir( Dir ){};
};

class chessMoveRecorder {
    std::vector< steps > stepList;
    int curStep;

public:
    bool if_UR;
    bool last_undo;
    chessMoveRecorder();
    void stepListClear();
    void pushChessMove( char& name, char& dir );      //向栈中储存棋子的移动数据
    void stepListClearPart();                         //在有新的输入之后清空前面的链表
    bool pullChessMoveLast( char& name, char& dir );  //返回上一个棋子的运动轨迹，以及是否能够回溯
    bool pullChessMoveNext( char& name, char& dir );
};

#endif  // CHESSMOVERECORDER_H