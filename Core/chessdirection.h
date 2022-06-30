#ifndef CHESSDIRECTION_H
#define CHESSDIRECTION_H

#include "chessglobal.h"
#include "chessconflict.h"

class chessDirection {
public:
    Cor dir;

public:
    chessDirection( const int& _x, const int& _y ) {
        dir.x = _x;
        dir.y = _y;
    }
    bool operator==( const chessDirection& _direction );
    void operator=( const chessDirection& _direction );
};

const chessDirection dir_left( -1, 0 );  //向左移动
const chessDirection dir_right( 1, 0 );  //向右移动
const chessDirection dir_up( 0, -1 );    //向上移动
const chessDirection dir_down( 0, 1 );   //向下移动

#endif