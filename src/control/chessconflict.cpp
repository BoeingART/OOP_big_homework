#include "../../include/control/chessconflict.h"

chessConflict::chessConflict() : occ( true ), name( '\0' ) {}

chessConflict::chessConflict( bool occ_, char name_ ) : occ( occ_ ), name( name_ ) {}

void chessConflict::operator=( chessConflict another ) {
    occ = another.occ;
    name = another.name;
}

chessBoard::chessBoard() {
    chessComplexion = new chessConflict*[ col ];
    for ( int i = 0; i < col; i++ )
        chessComplexion[ i ] = new chessConflict[ row ];
}

void chessBoard::chessBoardChange( const chessConflict board[ 4 ][ 5 ] ) {
    for ( int i = 0; i < col; i++ ) {
        for ( int j = 0; j < row; j++ ) {
            chessComplexion[ i ][ j ] = board[ i ][ j ];
        }
    }
}

chessConflict* const chessBoard::operator[]( const int i ) {
    return chessComplexion[ i ];
}

void chessBoard::operator=( chessBoard another ) {
    for ( int i = 0; i < col; i++ ) {
        for ( int j = 0; j < row; j++ ) {
            chessComplexion[ i ][ j ] = another[ i ][ j ];
        }
    }
}