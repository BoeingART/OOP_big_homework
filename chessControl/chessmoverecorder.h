#ifndef CHESSMOVERECORDER_H
#define CHESSMOVERECORDER_H

#include "chesscontrol.h"

struct steps{
    char dir;
    std::string name;
    steps(std::string Name = "empty", char Dir = '\0'): name(Name), dir(Dir){};
};

class chessMoveRecorder{
    std::stack<steps> stepList;
public:
    chessMoveRecorder();
    void stepListClear();
    void pushChessMove(std::string &name, char &dir); //向栈中储存棋子的移动数据
    bool pullChessMove(std::string &name, char &dir); //返回上一个棋子的运动轨迹，以及是否能够回溯
};


#endif // CHESSMOVERECORDER_H