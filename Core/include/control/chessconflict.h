#ifndef CHESSCONFLICT_H
#define CHESSCONFLICT_H

#include "../chessglobal.h"

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

class chessConflict {
public:
    bool occ;
    char name;

public:
    chessConflict();
    chessConflict( bool occ_, char name_ );
    void operator=( chessConflict another );
};

class chessBoard {
private:
    chessConflict** chessComplexion;
    const static int line = 4;
    const static int row = 5;

public:
    chessBoard();
    void chessBoardChange( const chessConflict board[ 4 ][ 5 ] );
    chessConflict* const operator[]( const int i );
};

#endif