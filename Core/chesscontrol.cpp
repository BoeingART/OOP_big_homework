#include "chesscontrol.h"
#include "chessdirection.h"

using namespace std;

globalConflict chessControl::chessBoard[ 4 ][ 5 ];  //棋盘局面的全局变量

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
    cout << "(" << direction.dir.x << ")"
         << "-"
         << "(" << direction.dir.y << ")";
    if ( onSide ) {
        cout << ": on the side, cannot move" << endl;
        cout << "please reinput." << endl;
    } else {
        cout << ": not on the side, can move" << endl;
    }
    // std::cout << "move" << std::endl;
    if ( onSide ) {
        return false;
    }
    return whetherMove( direction );
}

bool chessControl::whetherMove( chessDirection& direction ) {
    //首先删除该类中的位置占用信息，并将现在的坐标信息储存到一个新的坐标中
    Cor* tempCor = new Cor[ size ];
    for ( int i = 0; i < size; i++ ) {
        tempCor[ i ] = chessCurrentCor[ i ];
    }
    for ( int i = 0; i < size; i++ ) {
        chessBoard[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].occ = false;
        chessBoard[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].name = ' ';
    }
    //将棋子坐标向该方向移动

    for ( int i = 0; i < size; i++ ) {
        tempCor[ i ].x += direction.dir.x;
        tempCor[ i ].y += direction.dir.y;
    }

    //判断新的位置占用处是否有棋子被占用

    for ( int i = 0; i < size; i++ ) {
        if ( chessBoard[ tempCor[ i ].x - 1 ][ tempCor[ i ].y - 1 ].occ ) {
            cout << "(" << tempCor[ i ].x << "," << tempCor[ i ].y << ")"
                 << "处重叠了，是" << chessBoard[ tempCor[ i ].x - 1 ][ tempCor[ i ].y - 1 ].name << endl;
            for ( int j = 0; j < size; j++ ) {
                chessBoard[ chessCurrentCor[ j ].x - 1 ][ chessCurrentCor[ j ].y - 1 ].occ = true;
                chessBoard[ chessCurrentCor[ j ].x - 1 ][ chessCurrentCor[ j ].y - 1 ].name = this->chessName;
            }
            namedSpace();
            return false;
        }
    }
    //如果有棋子占用则返回当前坐标，同时将图中的信息进行添加，返回false

    for ( int i = 0; i < size; i++ ) {
        chessCurrentCor[ i ] = tempCor[ i ];
        chessBoard[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].occ = true;
        chessBoard[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].name = this->chessName;
    }
    //如果没有棋子占用则直接更新类中的坐标信息，并同时更新图的信息，返回true
    namedSpace();
    currentFocus.x += direction.dir.x;
    currentFocus.y += direction.dir.y;
    return true;
}

void chessControl::namedSpace() {
    char tag = 'p';
    for ( int i = 0; i < line; i++ ) {
        for ( int j = 0; j < row; j++ ) {
            if ( chessBoard[ i ][ j ].name == ' ' || chessBoard[ i ][ j ].name == 'p' || chessBoard[ i ][ j ].name == 'q' )
                chessBoard[ i ][ j ].name = tag++;
        }
    }
}

bool chessControl::whetherOnSide( chessDirection direction ) {
    bool onSide = false;
    if ( direction == dir_left )  //向左方
    {
        if ( chessCurrentCor[ 0 ].x <= 1 )
            onSide = true;
    } else if ( direction == dir_right )  //向右方
    {
        if ( chessCurrentCor[ size - 1 ].x >= line ) {
            onSide = true;
        }
    } else if ( direction == dir_up )  //向上方
    {
        if ( chessCurrentCor[ 0 ].y <= 1 )
            onSide = true;
    } else if ( direction == dir_down )  //向下方
    {
        if ( chessCurrentCor[ size - 1 ].y >= row )
            onSide = true;
    }
    return onSide;
}

void chessControl::chessReset() {
    chessCurrentCor = chessCorRecorder.chessPlace( chessName );
    for ( int i = 0; i < size; i++ )
        cout << chessCurrentCor[ i ].x << " " << chessCurrentCor[ i ].y << endl;
    std::cout << chessName << ": reseted" << std::endl;
}

void chessControl::chessBoardReset( std::string chessBoardName ) {
    chessCorRecorder.changeChessPlace( chessBoardName );
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            chessBoard[ i ][ j ] = chessCorRecorder.chessBoard( chessBoardName, i, j );
            cout << chessBoard[ i ][ j ].name << " ";
        }
        cout << "\n";
    }
}

bool chessControl::onside( Cor cor, char dir ) {
    if ( cor.y == 0 && dir == 'A' )
        return true;
    else if ( cor.y == row - 1 && dir == 'B' )
        return true;
    else if ( cor.x == line - 1 && dir == 'C' )
        return true;
    else if ( cor.x == 0 && dir == 'D' )
        return true;
    else
        return false;
}

char chessControl::chooseChess( char dir ) {
    char name_pre = chessBoard[ currentFocus.x ][ currentFocus.y ].name;
    if ( !onside( currentFocus, dir ) ) {
        if ( dir == 'A' )
            currentFocus.y -= 1;
        else if ( dir == 'B' )
            currentFocus.y += 1;
        else if ( dir == 'C' )
            currentFocus.x += 1;
        else if ( dir == 'D' )
            currentFocus.x -= 1;
    } else
        return name_pre;
    cout << currentFocus.x << ", " << currentFocus.y << endl;
    if ( name_pre == chessBoard[ currentFocus.x ][ currentFocus.y ].name && !onside( currentFocus, dir ) ) {
        cout << "same" << endl;
        return chooseChess( dir );
    } else {
        cout << name_pre << " " << chessBoard[ currentFocus.x ][ currentFocus.y ].name << endl;
        cout << "dif" << endl;
        return chessBoard[ currentFocus.x ][ currentFocus.y ].name;
    }
}

void chessControl::display( char name ) {
    system( "clear" );
    printf( "┏━━━━┳━━━━┳━━━━┳━━━━┓\n" );
    int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0;
    for ( int i = 0; i < row; i++ ) {
        printf( "┃" );
        for ( int j = 0; j < line; j++ ) {
            if ( chessBoard[ j ][ i ].occ ) {
                if ( chessBoard[ j ][ i ].name == 'c' ) {
                    if ( name == 'c' )
                        printf( "\033[1;31m" );
                    else
                        printf( "\033[31m" );
                    switch ( CC ) {
                    case 0:
                        printf( " 曹 " );
                        break;
                    case 1:
                        printf( " 曹 " );
                        break;
                    case 2:
                        printf( " 操 " );
                        break;
                    case 3:
                        printf( " 操 " );
                        break;
                    default:
                        break;
                    }
                    printf( "\033[0m" );
                    CC++;
                } else if ( chessBoard[ j ][ i ].name == 'f' ) {
                    if ( name == 'f' )
                        printf( "\033[1;32m" );
                    else
                        printf( "\033[32m" );
                    switch ( ZF ) {
                    case 0:
                        printf( " 张 " );
                        break;
                    case 1:
                        printf( " 飞 " );
                        break;
                    }
                    printf( "\033[0m" );
                    ZF++;
                } else if ( chessBoard[ j ][ i ].name == 'm' ) {
                    if ( name == 'm' )
                        printf( "\033[1;33m" );
                    else
                        printf( "\033[33m" );
                    switch ( MC ) {
                    case 0:
                        printf( " 马 " );
                        break;
                    case 1:
                        printf( " 超 " );
                        break;
                    }
                    printf( "\033[0m" );
                    MC++;
                } else if ( chessBoard[ j ][ i ].name == 'g' ) {
                    if ( name == 'g' )
                        printf( "\033[1;34m" );
                    else
                        printf( "\033[34m" );
                    switch ( GY ) {
                    case 0:
                        printf( " 关 " );
                        break;
                    case 1:
                        printf( " 羽 " );
                        break;
                    }
                    printf( "\033[0m" );
                    GY++;
                } else if ( chessBoard[ j ][ i ].name == 'h' ) {
                    if ( name == 'h' )
                        printf( "\033[1;35m" );
                    else
                        printf( "\033[35m" );
                    switch ( HZ ) {
                    case 0:
                        printf( " 黄 " );
                        break;
                    case 1:
                        printf( " 忠 " );
                        break;
                    }
                    printf( "\033[0m" );
                    HZ++;
                } else if ( chessBoard[ j ][ i ].name == 'y' ) {
                    if ( name == 'y' )
                        printf( "\033[1;36m" );
                    else
                        printf( "\033[36m" );
                    switch ( ZY ) {
                    case 0:
                        printf( " 赵 " );
                        break;
                    case 1:
                        printf( " 云 " );
                        break;
                    }
                    printf( "\033[0m" );
                    ZY++;
                } else if ( chessBoard[ j ][ i ].name == '1' ) {
                    if ( name == '1' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                } else if ( chessBoard[ j ][ i ].name == '2' ) {
                    if ( name == '2' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                } else if ( chessBoard[ j ][ i ].name == '3' ) {
                    if ( name == '3' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                } else if ( chessBoard[ j ][ i ].name == '4' ) {
                    if ( name == '4' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                }
            } else {
                if ( chessBoard[ j ][ i ].name == 'p' ) {
                    if ( name == 'p' )
                        printf( "\033[1;30m ██ \033[0m" );
                    else
                        printf( "\033[1;30m    \033[0m" );
                } else if ( chessBoard[ j ][ i ].name == 'q' ) {
                    if ( name == 'q' )
                        printf( "\033[1;30m ██ \033[0m" );
                    else
                        printf( "\033[1;30m    \033[0m" );
                }
            }
            printf( "┃" );
        }
        printf( "\n" );
        if ( i != row - 1 )
            printf( "┣━━━━╋━━━━╋━━━━╋━━━━┫\n" );
        else
            printf( "┗━━━━┻━━━━┻━━━━┻━━━━┛\n" );
    }
}

bool chessControl::checkCor( int x, int y ) {
    for ( int i = 0; i < size; i++ ) {
        if ( x == chessCurrentCor[ i ].x - 1 && y == chessCurrentCor[ i ].y - 1 ) {
            return true;
        }
    }
    return false;
}
