#ifndef CHESSCONTROL_H
#define CHESSCONTROL_H

//#include "global.h"
#include <iostream>
#include <cstring>

struct Cor{
    int x;
    int y;
};

class chessControl
{
public:
    chessControl(std::string name = "none");
    ~chessControl();
    bool chessCorChange(Cor direction);//移动棋子的函数，如果可以移动棋子则返回true，否则返回false
    static bool reachDestination();
    void chessReset();
    void testPrint();
    const static int line = 4;
    const static int row = 5;
    static Cor dir_left;
    static Cor dir_right;
    static Cor dir_up;
    static Cor dir_down;

protected:
    int size;
    static bool corOccupied[4][5];
    static bool finishInit;
    static void recordChessMove();
    std::string chessName;
    Cor *chessCurrentCor;
    bool whetherOnSide(Cor direction);
    bool whetherMove(Cor &direction);
    bool checkCor(int x, int y);
};


#endif // CHESSCONTROL_H
