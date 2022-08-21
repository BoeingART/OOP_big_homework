#ifndef CHESSCONFLICT_H
#define CHESSCONFLICT_H

#include "../chessglobal.h"

//坐标类
struct Cor {
    int x;
    int y;
    void operator=( const Cor& another ) {
        x = another.x;
        y = another.y;
    }
    void operator+=( const Cor& another ) {
        x += another.x;
        y += another.y;
    }
};

//某处棋盘占据情况类
class chessConflict {
public:
    bool occ;   //是否占据
    char name;  //棋子名字
    chessConflict();
    chessConflict( bool occ_, char name_ );
    void operator=( chessConflict another );
};

//棋盘局面情况类
class chessBoard {
private:
    chessConflict** chessComplexion;  //棋盘局面
    const static int col = 4;         //棋盘列数col=4
    const static int row = 5;         //棋盘行数row=5

public:
    chessBoard();
    void chessBoardChange( const chessConflict board[ col ][ row ] );  /
    chessConflict* const operator[]( const int i );
    void operator=( chessBoard another );
};

#endif