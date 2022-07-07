
#include "../include/chessmain.h"
using namespace std;

chessMain::chessMain() : chessName( 'c' ) {
    //初始化各种棋子
    cc = new chessControlSize4( 'c' );
    zf = new chessControlSize2( 'f' );
    hz = new chessControlSize2( 'h' );
    gy = new chessControlSize2( 'g' );
    mc = new chessControlSize2( 'm' );
    zy = new chessControlSize2( 'y' );
    bA = new chessControlSize1( '1' );
    bB = new chessControlSize1( '2' );
    bC = new chessControlSize1( '3' );
    bD = new chessControlSize1( '4' );
    //初始化棋子移动记录器
    Recorder = new chessMoveRecorder();
    globalDisplay = new chessDisplay();
    globalSolute = new chessSolute();
    keypad( globalDisplay->chessGameBoard, true );
}

chessMain::chessMain( char test ) {
    //初始化各种棋子
    cc = new chessControlSize4( 'c' );
    zf = new chessControlSize2( 'f' );
    hz = new chessControlSize2( 'h' );
    gy = new chessControlSize2( 'g' );
    mc = new chessControlSize2( 'm' );
    zy = new chessControlSize2( 'y' );
    bA = new chessControlSize1( '1' );
    bB = new chessControlSize1( '2' );
    bC = new chessControlSize1( '3' );
    bD = new chessControlSize1( '4' );
    Recorder = new chessMoveRecorder();
    chessReset();
    globalSolute = new chessSolute();
}

chessMain::~chessMain() {
    delete cc;
    delete zf;
    delete hz;
    delete gy;
    delete mc;
    delete zy;
    delete bA;
    delete bB;
    delete bC;
    delete bD;
    delete Recorder;
    delete globalDisplay;
}

void chessMain::chessHighLight( const char& name ) {
    this->globalDisplay->display( name );
}

int chessMain::chessChoose( int input ) {
    return chessControl::chooseChess( input );
}

bool chessMain::chessMove( char name, char dir ) {
    //如果上一次是undo而本次移动了，则将移动部分的步骤列表进行清除
    if ( Recorder->last_undo )
        Recorder->stepListClearPart();
    char direction;
    //对方向进行转换（出于一些历史原因）
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
    //将字符方向转换为Cor类型
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
        if_move = cc->chessCorChange( dir );
    else if ( name == 'f' )
        if_move = zf->chessCorChange( dir );
    else if ( name == 'm' )
        if_move = mc->chessCorChange( dir );
    else if ( name == 'g' )
        if_move = gy->chessCorChange( dir );
    else if ( name == 'y' )
        if_move = zy->chessCorChange( dir );
    else if ( name == 'h' )
        if_move = hz->chessCorChange( dir );
    else if ( name == '1' )
        if_move = bA->chessCorChange( dir );
    else if ( name == '2' )
        if_move = bB->chessCorChange( dir );
    else if ( name == '3' )
        if_move = bC->chessCorChange( dir );
    else if ( name == '4' )
        if_move = bD->chessCorChange( dir );
    else
        return false;
    //如果可以棋子可以移动且不是undo
    if ( !Recorder->if_UR && if_move )
        Recorder->pushChessMove( name, direction );
    Recorder->if_UR = false;
    if ( if_move )
        return true;
    else
        return false;
}

char chessMain::chessReset( char chessBoardNumber ) {
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
        return '\0';
    chessControl::chessBoardReset( chessBoardName );
    cc->chessReset();
    zf->chessReset();
    mc->chessReset();
    gy->chessReset();
    zy->chessReset();
    hz->chessReset();
    bA->chessReset();
    bB->chessReset();
    bC->chessReset();
    bD->chessReset();
    Recorder->stepListClear();
    chessControl::currentFocus = getFocusCor( 'c' );
    return 'c';
}

Cor chessMain::getFocusCor( char name ) {
    for ( int i = 0; i < chessMain::line(); i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            if ( chessControl::chessCurrentComplextion( i, j ).name == name )
                return { i, j };
        }
    }
    return { 0, 0 };
}

char chessMain::chessRedo( char& name ) {
    char dir;
    if ( !Recorder->pullChessMoveNext( name, dir ) )
        return false;
    else {
        Recorder->if_UR = true;
        if ( inputChessInfo( name, dir ) ) {
            chessControl::currentFocus = getFocusCor( name );
            return name;
        } else
            return false;
    }
}

char chessMain::chessUndo( char& name ) {
    char dir;
    if ( !Recorder->pullChessMoveLast( name, dir ) )
        return false;
    else {
        Recorder->if_UR = true;
        Recorder->last_undo = true;
        dirChange( dir );
    }
    if ( inputChessInfo( name, dir ) ) {
        chessControl::currentFocus = getFocusCor( name );
        return name;
    } else
        return false;
}

void chessMain::chessEnd() {
    printf( "游戏结束\n" );
}

bool chessMain::chessReachDestination() {
    if ( cc->reachDestination() ) {
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

const char* chessMain::chessBoardInfo( const int line, const int row, const int charNumber ) {
    switch ( chessControl::chessCurrentComplextion( line, row ).name ) {
    case 'c':
        switch ( charNumber ) {
        case 0:
            return "曹";
        case 1:
            return "";
        case 2:
            return "操";
        case 3:
            return "";
        }
    case 'f':
        switch ( charNumber ) {
        case 0:
            return "张";
        case 1:
            return "飞";
        }
    case 'g':
        switch ( charNumber ) {
        case 0:
            return "关";
        case 1:
            return "羽";
        }
    case 'y':
        switch ( charNumber ) {
        case 0:
            return "赵";
        case 1:
            return "云";
        }
    case 'm':
        switch ( charNumber ) {
        case 0:
            return "马";
        case 1:
            return "超";
        }
    case 'h':
        switch ( charNumber ) {
        case 0:
            return "黄";
        case 1:
            return "忠";
        }
    case '1':
        return "兵";
    case '2':
        return "兵";
    case '3':
        return "兵";
    case '4':
        return "兵";
    case 'p':
        return "  ";
    case 'q':
        return "  ";
    default:
        return "\0\0";
        break;
    }
}

int chessMain::line() {
    return chessControl::line;
}

int chessMain::row() {
    return chessControl::row;
}

int chessMain::getInput() {
    return globalDisplay->gameBoardInput();
}