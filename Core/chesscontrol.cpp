#include "chesscontrol.h"
#include "chessdirection.h"

using namespace std;

globalConflict chessControl::chessBoard[ 4 ][ 5 ];  //棋盘局面的全局变量

originChessCor chessControl::chessCorRecorder;  //

chessControl::chessControl( std::string name )
    : chessName( name ) {
    if ( name == "none" ) {
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
        chessBoard[ chessCurrentCor[ i ].x - 1 ][ chessCurrentCor[ i ].y - 1 ].name = "\0";
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

    return true;
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

void chessControl::display() {
    printf( "┏━━━━┳━━━━┳━━━━┳━━━━┓\n" );
    int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0, BA = 0, BB = 0, BC = 0, BD = 0;
    for ( int i = 0; i < row; i++ ) {
        printf( "┃" );
        for ( int j = 0; j < line; j++ ) {
            if ( chessBoard[ j ][ i ].occ ) {
                if ( chessBoard[ j ][ i ].name == "cc" ) {
                    switch ( CC ) {
                    case 0:
                        printf( "\033[31;1m 曹 \033[0m" );
                        break;
                    case 1:
                        printf( "\033[31;1m 曹 \033[0m" );
                        break;
                    case 2:
                        printf( "\033[31;1m 操 \033[0m" );
                        break;
                    case 3:
                        printf( "\033[31;1m 操 \033[0m" );
                        break;
                    default:
                        break;
                    }
                    CC++;
                } else if ( chessBoard[ j ][ i ].name == "zf" ) {
                    switch ( ZF ) {
                    case 0:
                        printf( "\033[32;1m 张 \033[0m" );
                        break;
                    case 1:
                        printf( "\033[32;1m 飞 \033[0m" );
                        break;
                    }
                    ZF++;
                } else if ( chessBoard[ j ][ i ].name == "mc" ) {
                    switch ( MC ) {
                    case 0:
                        printf( "\033[33;1m 马 \033[0m" );
                        break;
                    case 1:
                        printf( "\033[33;1m 超 \033[0m" );
                        break;
                    }
                    MC++;
                } else if ( chessBoard[ j ][ i ].name == "gy" ) {
                    switch ( GY ) {
                    case 0:
                        printf( "\033[34;1m 关 \033[0m" );
                        break;
                    case 1:
                        printf( "\033[34;1m 羽 \033[0m" );
                        break;
                    }
                    GY++;
                } else if ( chessBoard[ j ][ i ].name == "hz" ) {
                    switch ( HZ ) {
                    case 0:
                        printf( "\033[35;1m 黄 \033[0m" );
                        break;
                    case 1:
                        printf( "\033[35;1m 忠 \033[0m" );
                        break;
                    }
                    HZ++;
                } else if ( chessBoard[ j ][ i ].name == "zy" ) {
                    switch ( ZY ) {
                    case 0:
                        printf( "\033[36;1m 赵 \033[0m" );
                        break;
                    case 1:
                        printf( "\033[36;1m 云 \033[0m" );
                        break;
                    }
                    ZY++;
                } else if ( chessBoard[ j ][ i ].name == "ba" ) {
                    printf( "\033[37;1m 兵 \033[0m" );
                } else if ( chessBoard[ j ][ i ].name == "bb" ) {
                    printf( "\033[37;1m 兵 \033[0m" );
                } else if ( chessBoard[ j ][ i ].name == "bc" ) {
                    printf( "\033[37;1m 兵 \033[0m" );
                } else if ( chessBoard[ j ][ i ].name == "bd" ) {
                    printf( "\033[37;1m 兵 \033[0m" );
                }
            } else {
                printf( "    " );
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
