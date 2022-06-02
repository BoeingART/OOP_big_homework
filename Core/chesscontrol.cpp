#include "chesscontrol.h"
#include "chessdirection.h"
using namespace std;

// globalConflict chessControl::chessBoard[ 4 ][ 5 ] = { { originChessBoard[ 0 ] }, { originChessBoard[ 1 ] }, { originChessBoard[ 2 ] }, { originChessBoard[ 3 ] } };
globalConflict chessControl::chessBoard[ 4 ][ 5 ] = { { { true, "zf" }, { true, "zf" }, { true, "hz" }, { true, "hz" }, { true, "ba" } },
                                                      { { true, "cc" }, { true, "cc" }, { false, "\0" }, { true, "gy" }, { true, "bb" } },
                                                      { { true, "cc" }, { true, "cc" }, { false, "\0" }, { true, "gy" }, { true, "bc" } },
                                                      { { true, "mc" }, { true, "mc" }, { true, "zy" }, { true, "zy" }, { true, "bd" } } };

chessControl::chessControl( std::string name )
    : chessName( name ) {
    if ( name == "none" ) {
        std::cerr << "please put a name in" << std::endl;
        return;
    }
}

chessControl::~chessControl() {
    delete[] chessCurrentCor;
    // std::cout << "main:delete" << std::endl;
}

bool chessControl::chessCorChange( chessDirection direction ) {
    bool onSide = whetherOnSide( direction );
    cout << "(" << direction.dir.x << ")"
         << "-"
         << "(" << direction.dir.y << ")";
    if ( onSide ) {
        cout << ": on the side, cannot move" << endl;
        cout << "please reinput." << endl;
    }
    else {
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
                 << "处重叠了" << endl;
            for ( int j = 0; j < size; j++ ) {
                chessBoard[ chessCurrentCor[ j ].x - 1 ][ chessCurrentCor[ j ].y - 1 ].occ = true;
                chessBoard[ chessCurrentCor[ j ].x - 1 ][ chessCurrentCor[ j ].y - 1 ].name = this->chessName;
            }
            return false;
            //如果有棋子占用则返回当前坐标，同时将图中的信息进行添加，返回false
        }
    }
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
        if ( chessCurrentCor[ 0 ].x <= 1 ) onSide = true;
    }
    else if ( direction == dir_right )  //向右方
    {
        if ( chessCurrentCor[ size - 1 ].x >= line ) {
            onSide = true;
        }
    }
    else if ( direction == dir_up )  //向上方
    {
        if ( chessCurrentCor[ 0 ].y <= 1 ) onSide = true;
    }
    else if ( direction == dir_down )  //向下方
    {
        if ( chessCurrentCor[ size - 1 ].y >= row ) onSide = true;
    }
    return onSide;
}

void chessControl::chessReset() {

    if ( chessName == "cc" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_cc[ i ];
        }
    }
    else if ( chessName == "zf" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_zf[ i ];
        }
    }
    else if ( chessName == "hz" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_hz[ i ];
        }
    }
    else if ( chessName == "gy" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_gy[ i ];
        }
    }
    else if ( chessName == "mc" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_mc[ i ];
        }
    }
    else if ( chessName == "zy" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_zy[ i ];
        }
    }
    else if ( chessName == "ba" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_ba[ i ];
        }
    }
    else if ( chessName == "bb" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_bb[ i ];
        }
    }
    else if ( chessName == "bc" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_bc[ i ];
        }
    }
    else if ( chessName == "bd" ) {
        for ( int i = 0; i < size; i++ ) {
            chessCurrentCor[ i ] = cor_bd[ i ];
        }
    }

    std::cout << chessName << ": reseted" << std::endl;
}

void chessControl::chessBoardReset() {
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            chessBoard[ i ][ j ] = originChessBoard[ i ][ j ];
        }
    }
}

void chessControl::display() {
    cout << "┏━━━┳━━━┳━━━┳━━━┓" << endl;
    for ( int i = 0; i < row; i++ ) {
        cout << "┃";
        for ( int j = 0; j < line; j++ ) {
            //     if(checkCor(j, i)){
            //         std::cout << "*";
            //     }else if(chessBoard[j][i] == true){
            //         std::cout << "·";
            //     }else{
            //         std::cout << "-";
            //     }
            if ( chessBoard[ j ][ i ].occ ) {
                if ( chessBoard[ j ][ i ].name == "cc" ) {
                    cout << "\033[31;1m"
                         << " C "
                         << "\033[0m";
                }
                else if ( chessBoard[ j ][ i ].name == "zf" ) {
                    cout << "\033[32;1m"
                         << " F "
                         << "\033[0m";
                }
                else if ( chessBoard[ j ][ i ].name == "mc" ) {
                    cout << "\033[33;1m"
                         << " M "
                         << "\033[0m";
                }
                else if ( chessBoard[ j ][ i ].name == "gy" ) {
                    cout << "\033[34;1m"
                         << " G "
                         << "\033[0m";
                }
                else if ( chessBoard[ j ][ i ].name == "hz" ) {
                    cout << "\033[35;1m"
                         << " H "
                         << "\033[0m";
                }
                else if ( chessBoard[ j ][ i ].name == "zy" ) {
                    cout << "\033[36;1m"
                         << " Y "
                         << "\033[0m";
                }
                else if ( chessBoard[ j ][ i ].name == "ba" ) {
                    cout << " a ";
                }
                else if ( chessBoard[ j ][ i ].name == "bb" ) {
                    cout << " b ";
                }
                else if ( chessBoard[ j ][ i ].name == "bc" ) {
                    cout << " c ";
                }
                else if ( chessBoard[ j ][ i ].name == "bd" ) {
                    cout << " d ";
                }
            }
            else {
                cout << "   ";
            }
            cout << "┃";
        }
        cout << endl;
        if ( i != row - 1 )
            cout << "┣━━━╋━━━╋━━━╋━━━┫" << endl;
        else
            cout << "┗━━━┻━━━┻━━━┻━━━┛" << endl;
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
