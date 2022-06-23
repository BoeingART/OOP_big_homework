
#include "chessmain.h"
using namespace std;

chessControlSize4 cc( 'c' );
chessControlSize2 zf( 'f' );
chessControlSize2 hz( 'h' );
chessControlSize2 gy( 'g' );
chessControlSize2 mc( 'm' );
chessControlSize2 zy( 'y' );
chessControlSize1 bA( '1' );
chessControlSize1 bB( '2' );
chessControlSize1 bC( '3' );
chessControlSize1 bD( '4' );

chessMoveRecorder Recorder;

chessMain::chessMain()
    : chessName( 'c' ) {}

void chessMain::chessHighLight( char name ) {
    chessDisplay::display( name );
}

bool chessMain::chessMove( char name, char dir ) {
    if ( Recorder.last_undo )
        Recorder.stepListClearPart();
    char direction;
    if ( dir == 'w' )
        direction = 'u';
    else if ( dir == 's' )
        direction = 'd';
    else if ( dir == 'a' )
        direction = 'l';
    else if ( dir == 'd' )
        direction = 'r';
    return inputChessInfo( name, direction );
}

bool chessMain::inputChessInfo( char name, char direction ) {
    chessDirection dir( 0, 0 );
    switch ( direction ) {
    case 'u':
        dir = dir_up;
        break;
    case 'd':
        dir = dir_down;
        break;
    case 'l':
        dir = dir_left;
        break;
    case 'r':
        dir = dir_right;
        break;
    default:
        return false;
    }

    bool if_move = true;
    if ( name == 'c' )
        if_move = cc.chessCorChange( dir );
    else if ( name == 'f' )
        if_move = zf.chessCorChange( dir );
    else if ( name == 'm' )
        if_move = mc.chessCorChange( dir );
    else if ( name == 'g' )
        if_move = gy.chessCorChange( dir );
    else if ( name == 'y' )
        if_move = zy.chessCorChange( dir );
    else if ( name == 'h' )
        if_move = hz.chessCorChange( dir );
    else if ( name == '1' )
        if_move = bA.chessCorChange( dir );
    else if ( name == '2' )
        if_move = bB.chessCorChange( dir );
    else if ( name == '3' )
        if_move = bC.chessCorChange( dir );
    else if ( name == '4' )
        if_move = bD.chessCorChange( dir );
    else
        return false;
    if ( !Recorder.if_UR && if_move )
        Recorder.pushChessMove( name, direction );
    Recorder.if_UR = false;
    if ( if_move ) {
        return true;
    } else {
        return false;
    }
}

bool chessMain::chessReset( char chessBoardNumber ) {
    try {
        std::string chessBoardName;
        if ( chessBoardNumber == '0' )
            chessBoardName = "horizontal_knife";
        else if ( chessBoardNumber == '1' )
            chessBoardName = "neck_and_neck";
        else if ( chessBoardNumber == '2' )
            chessBoardName = "three_road";
        else if ( chessBoardNumber == '3' )
            chessBoardName = "station_troops";
        else if ( chessBoardNumber == '4' )
            chessBoardName = "left_and_right";
        else if ( chessBoardNumber == '~' )
            chessBoardName = "test";
        else
            chessBoardName = "horizontal_knife";
        chessControl::chessBoardReset( chessBoardName );
        cc.chessReset();
        zf.chessReset();
        mc.chessReset();
        gy.chessReset();
        zy.chessReset();
        hz.chessReset();
        bA.chessReset();
        bB.chessReset();
        bC.chessReset();
        bD.chessReset();
        Recorder.stepListClear();
        return true;
    }
    catch ( ... ) {
        return false;
    }
}

bool chessMain::chessRedu() {
    char name;
    char dir;
    if ( !Recorder.pullChessMoveNext( name, dir ) ) {
        return false;
    } else {
        Recorder.if_UR = true;
        if ( inputChessInfo( name, dir ) ) {
            return true;
        } else {
            return false;
        }
    }
}

bool chessMain::chessUndo() {
    char name;
    char dir;
    if ( !Recorder.pullChessMoveLast( name, dir ) ) {
        return false;
    } else {
        Recorder.if_UR = true;
        Recorder.last_undo = true;
        dirChange( dir );
    }
    if ( inputChessInfo( name, dir ) ) {
        return true;
    } else {
        return false;
    }
}

void chessMain::chessEnd() {
    printf( "游戏结束\n" );
}

bool chessMain::chessReachDestination() {
    if ( cc.reachDestination() ) {
        printf( "到达世界最高城——理塘！\n" );
        printf( "太美丽啦理塘\n" );
        printf( "诶，这不是丁真吗\n" );
        printf( "还是再看看远处的雪山吧家人们\n" );
        return true;
    } else
        return false;
}

void chessMain::dirChange( char& Dir ) {
    switch ( Dir ) {
    case 'u':
        Dir = 'd';
        break;
    case 'd':
        Dir = 'u';
        break;
    case 'l':
        Dir = 'r';
        break;
    case 'r':
        Dir = 'l';
        break;
    default:
        break;
    }
}
