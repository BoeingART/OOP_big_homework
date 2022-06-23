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
    bool chessMove( char directionn );
    bool chessReset( char chessBoardName = '0' );
    bool chessRedu();
    bool chessUndo();
    bool chessReachDestination();
    void chessEnd();
    char chessChoose( char dir );
    char chessName;

private:
    bool inputChessInfo( char name, char direction );
    void dirChange( char& Dir );
};

int scanKeyboard();

#endif