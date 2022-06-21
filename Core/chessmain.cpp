
#include "chessmain.h"
using namespace std;

chessControlSize4 cc( "cc" );
chessControlSize2 zf( "zf" );
chessControlSize2 hz( "hz" );
chessControlSize2 gy( "gy" );
chessControlSize2 mc( "mc" );
chessControlSize2 zy( "zy" );
chessControlSize1 bA( "ba" );
chessControlSize1 bB( "bb" );
chessControlSize1 bC( "bc" );
chessControlSize1 bD( "bd" );

chessMoveRecorder Recorder;

bool chessMain::chessMove( std::string name, char direction ) {
    if ( Recorder.last_undo )
        Recorder.stepListClearPart();
    return inputChessInfo( name, direction );
}

bool chessMain::inputChessInfo( std::string name, char direction ) {

    if ( direction != 'u' && direction != 'd' && direction != 'l' && direction != 'r' ) {
        cout << "direction is " << direction << endl;
        cout << "error input in direction" << endl;
        // chessControl::display();
        return false;
    }

    chessDirection dir( 0, 0 );
    // cout << "doing info" << endl;
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
        // chessControl::display();
        return false;
    }

    bool if_move = true;
    if ( name == "cc" ) {
        if_move = cc.chessCorChange( dir );
    } else if ( name == "f" ) {
        if_move = zf.chessCorChange( dir );
    } else if ( name == "m" ) {
        if_move = mc.chessCorChange( dir );
    } else if ( name == "g" ) {
        if_move = gy.chessCorChange( dir );
    } else if ( name == "y" ) {
        if_move = zy.chessCorChange( dir );
    } else if ( name == "h" ) {
        if_move = hz.chessCorChange( dir );
    } else if ( name == "a" ) {
        if_move = bA.chessCorChange( dir );
    } else if ( name == "b" ) {
        if_move = bB.chessCorChange( dir );
    } else if ( name == "c" ) {
        if_move = bC.chessCorChange( dir );
    } else if ( name == "d" ) {
        if_move = bD.chessCorChange( dir );
    }
    if ( !Recorder.if_UR && if_move )
        Recorder.pushChessMove( name, direction );
    Recorder.if_UR = false;
    if ( if_move ) {
        return true;
    } else {
        return false;
    }
}

bool chessMain::chessReset() {
    try {
        chessControl::chessBoardReset();
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
    string name;
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
    std::string name;
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
