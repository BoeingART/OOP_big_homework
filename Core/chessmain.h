#ifndef CHESSMAIN_H
#define CHESSMAIN_H

#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
#include "chessdirection.h"
#include "chessdisplay.h"
#include "chessglobal.h"
#include "chessmoverecorder.h"
#include <stdio.h>

class chessMain {
public:
    chessMain();
    void chessHighLight( char name );
    bool chessMove( char name, char directionn );
    bool chessReset( char chessBoardNumber = '0' );
    bool chessRedu();
    bool chessUndo();
    bool chessReachDestination();
    void chessEnd();
    globalConflict chessBoardInfo( int i, int j );  //获取棋盘上第i行第j列的元素信息

private:
    bool inputChessInfo( char name, char direction );
    void dirChange( char& Dir );
    char chessName;
};

int scanKeyboard();
#endif