#ifndef CHESSMAIN_H
#define CHESSMAIN_H


#include "chessglobal.h"

#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
#include "chessmoverecorder.h"
#include "chessdirection.h"
#include <stdio.h>


class chessMain{
public:
    bool chessMove(std::string name, char directionn);
    bool chessReset();
    bool chessRedu();
    bool chessUndo();
    bool chessReachDestination();
    void chessEnd();
private:
    bool inputChessInfo(std::string name, char direction);
    void dirChange(char &Dir);
};

#endif