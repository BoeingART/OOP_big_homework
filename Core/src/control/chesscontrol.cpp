#include "../../include/control/chesscontrol.h"
#include "../../include/control/chessdirection.h"

using namespace std;

chessBoard chessControl::chessComplexion;  //棋盘局面的全局变量

originChessCor chessControl::chessCorRecorder;  //初始局面记录

Cor chessControl::currentFocus = { 0, 0 };  //焦点棋子

chessControl::chessControl( char name )
    : chessName( name ) {
    if ( name == 'n' ) {
        std::cerr << "please put a name in" << std::endl;
        return;
    }
}

chessControl::~chessControl() {
    delete[] chessCurrentCor;
}

bool chessControl::chessCorChange( chessDirection direction ) {
    bool onSide = whetherOnSide( direction );
    if ( onSide )
        return false;  //如果棋子在边缘则不可移动，返回false
    return whetherMove( direction );
}

bool chessControl::whetherMove( chessDirection& direction ) {
    //首先删除该类中的位置占用信息，并将现在的坐标信息储存到一个新的坐标中
    Cor* tempCor = new Cor[ size ];
    for ( int i = 0; i < size; i++ ) {
        tempCor[ i ] = chessCurrentCor[ i ];
    }
    for ( int i = 0; i < size; i++ ) {
        chessComplexion[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].occ = false;
        chessComplexion[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].name = ' ';
    }

    //将棋子坐标向该方向移动
    for ( int i = 0; i < size; i++ )
        tempCor[ i ] += direction.dir;

    //判断新的位置占用处是否有棋子被占用
    for ( int i = 0; i < size; i++ ) {
        //如果有棋子占用则返回当前坐标，同时将图中的信息进行添加，返回false
        if ( chessComplexion[ tempCor[ i ].x - 1 ][ tempCor[ i ].y - 1 ].occ ) {
            for ( int j = 0; j < size; j++ ) {
                chessComplexion[ chessCurrentCor[ j ].x - 1 ][ chessCurrentCor[ j ].y - 1 ].occ = true;
                chessComplexion[ chessCurrentCor[ j ].x - 1 ][ chessCurrentCor[ j ].y - 1 ].name = this->chessName;
            }
            namedSpace();
            return false;
        }
    }

    //如果没有棋子占用则直接更新类中的坐标信息，并同时更新图的信息，返回true
    for ( int i = 0; i < size; i++ ) {
        chessCurrentCor[ i ] = tempCor[ i ];
        chessComplexion[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].occ = true;
        chessComplexion[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].name = this->chessName;
    }
    namedSpace();
    currentFocus += direction.dir;
    return true;
}

void chessControl::namedSpace() {
    char tag = 'p';
    for ( int i = 0; i < line; i++ ) {
        for ( int j = 0; j < row; j++ ) {
            if ( chessComplexion[ i ][ j ].name == ' ' || chessComplexion[ i ][ j ].name == 'p' || chessComplexion[ i ][ j ].name == 'q' )
                chessComplexion[ i ][ j ].name = tag++;
        }
    }
}

bool chessControl::whetherOnSide( chessDirection direction ) {
    if ( direction == dir_left ) {
        if ( chessCurrentCor[ 0 ].x <= 1 )
            return true;
    } else if ( direction == dir_right ) {
        if ( chessCurrentCor[ size - 1 ].x >= line )
            return true;
    } else if ( direction == dir_up ) {
        if ( chessCurrentCor[ 0 ].y <= 1 )
            return true;
    } else if ( direction == dir_down ) {
        if ( chessCurrentCor[ size - 1 ].y >= row )
            return true;
    }
    return false;
}

void chessControl::chessReset() {
    chessCurrentCor = chessCorRecorder.chessPlace( chessName );
}

void chessControl::chessBoardReset( std::string chessBoardName ) {
    chessCorRecorder.changeChessPlace( chessBoardName );
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 5; j++ )
            chessComplexion[ i ][ j ] = chessCorRecorder.chessBoard( chessBoardName, i, j );
    }
}

bool chessControl::onside( Cor cor, int dir ) {
    if ( cor.y == 0 && dir == KEY_UP )
        return true;
    else if ( cor.y == row - 1 && dir == KEY_DOWN )
        return true;
    else if ( cor.x == line - 1 && dir == KEY_RIGHT )
        return true;
    else if ( cor.x == 0 && dir == KEY_LEFT )
        return true;
    else
        return false;
}

char chessControl::chooseChess( int dir ) {
    char name_pre = chessComplexion[ currentFocus.x ][ currentFocus.y ].name;
    if ( !onside( currentFocus, dir ) ) {
        if ( dir == KEY_UP )
            currentFocus.y -= 1;
        else if ( dir == KEY_DOWN )
            currentFocus.y += 1;
        else if ( dir == KEY_RIGHT )
            currentFocus.x += 1;
        else if ( dir == KEY_LEFT )
            currentFocus.x -= 1;
    } else
        return name_pre;
    if ( name_pre == chessComplexion[ currentFocus.x ][ currentFocus.y ].name && !onside( currentFocus, dir ) )
        return chooseChess( dir );
    else
        return chessComplexion[ currentFocus.x ][ currentFocus.y ].name;
}

bool chessControl::checkCor( int x, int y ) {
    for ( int i = 0; i < size; i++ ) {
        if ( x == chessCurrentCor[ i ].x - 1 && y == chessCurrentCor[ i ].y - 1 ) {
            return true;
        }
    }
    return false;
}

chessConflict chessControl::chessCurrentComplextion( int i, int j ) {
    return chessComplexion[ i ][ j ];
}