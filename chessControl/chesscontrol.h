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
    bool chessCorChange();//移动棋子的函数，如果可以移动棋子则返回true，否则返回false
    static bool reachDestination();
    void chessReset();
    static void testPrint();
    const static int line = 4;
    const static int row = 5;

protected:

    static bool corOccupied[4][5];
    static bool finishInit;
    static void recordChessMove(int direction);
    std::string chessName;
    Cor *chessCurrentCor;
};


#endif // CHESSCONTROL_H
