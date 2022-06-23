#ifndef CHESSMAIN_H
#define CHESSMAIN_H

#include "chessglobal.h"
#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
#include "chessdirection.h"
#include "chessmoverecorder.h"
#include <stdio.h>

class chessMain {
public:
    void chessHighLight( char name );
    bool chessMove( char name, char directionn );
    bool chessReset( std::string chessBoardName = "horizontal_horizontal_knife" );
    bool chessRedu();
    bool chessUndo();
    bool chessReachDestination();
    void chessEnd();

private:
    bool inputChessInfo( char name, char direction );
    void dirChange( char& Dir );
};

#endif