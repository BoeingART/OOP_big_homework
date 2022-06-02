#ifndef CHESSMOVERECORDER_H
#define CHESSMOVERECORDER_H

#include "chesscontrol.h"

struct steps {
    char dir;
    std::string name;
    steps( std::string Name = "empty", char Dir = '\0' ) : name( Name ), dir( Dir ){};
};

class chessMoveRecorder {
    std::vector< steps > stepList;
    int curStep;

    void testPrint();

public:
    bool if_UR;
    bool last_undo;
    chessMoveRecorder();
    void stepListClear();
    void pushChessMove( std::string& name, char& dir );      //向栈中储存棋子的移动数据
    void stepListClearPart();                                //在有新的输入之后清空前面的链表
    bool pullChessMoveLast( std::string& name, char& dir );  //返回上一个棋子的运动轨迹，以及是否能够回溯
    bool pullChessMoveNext( std::string& name, char& dir );
};

#endif  // CHESSMOVERECORDER_H