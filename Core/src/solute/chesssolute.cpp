#include "../../include/solute/chesssolute.h"
using namespace std;

chessSolute::chessSolute() {
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            currentComplextion[ i ][ j ] = chessControl::chessCurrentComplextion( i, j );
            printf( "%c ", currentComplextion[ i ][ j ].name );
        }
        printf( "\n" );
    }
}