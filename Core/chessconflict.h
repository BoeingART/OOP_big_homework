#ifndef CHESSCONFLICT_H
#define CHESSCONFLICT_H

#include "chessglobal.h"

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
    chessConflict()
        : occ( true )
        , name( '\0' ) {}
    chessConflict( bool occ_, char name_ )
        : occ( occ_ )
        , name( name_ ) {}
    void operator=( chessConflict another ) {
        occ = another.occ;
        name = another.name;
    }
};

class chessBoard {
private:
    chessConflict** chessComplexion;
    const static int line = 4;
    const static int row = 5;

public:
    chessBoard() {
        chessComplexion = new chessConflict*[ line ];
        for ( int i = 0; i < line; i++ )
            chessComplexion[ i ] = new chessConflict[ row ];
    }
    void chessBoardChange( const chessConflict board[ 4 ][ 5 ] ) {
        for ( int i = 0; i < line; i++ ) {
            for ( int j = 0; j < row; j++ ) {
                chessComplexion[ i ][ j ] = board[ i ][ j ];
            }
        }
    }
    chessConflict* const operator[]( const int i ) {
        return chessComplexion[ i ];
    }

};

#endif