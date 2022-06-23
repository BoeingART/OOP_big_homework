
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

void chessMain::chessHighLight( char name ) {
    chessControl::display( name );
}

bool chessMain::chessMove( char name, char dir ) {
    if ( Recorder.last_undo )
        Recorder.stepListClearPart();
    char direction;
    cout << "the dir is " << dir << endl;
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
        cout << "错误输入指令" << endl;
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

bool chessMain::chessReset( std::string chessBoardName ) {
    try {
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
        // cout << "cannot undo." << endl;
        // chessControl::display();
        return false;
    } else {
        Recorder.if_UR = true;
        // last_undo = true;
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
    cout << "游戏结束" << endl;
}

bool chessMain::chessReachDestination() {
    if ( cc.reachDestination() ) {
        cout << "到达世界最高城——理塘！" << endl;
        cout << "太美丽啦理塘" << endl;
        cout << "诶，这不是丁真吗" << endl;
        cout << "还是再看看远处的雪山吧家人们" << endl;
        return true;
    } else {
        return false;
    }
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
