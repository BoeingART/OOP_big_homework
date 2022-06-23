#include "chesscontrolsize2.h"
using namespace std;

chessControlSize2::chessControlSize2( char name )
    : chessControl( name ) {
    size = 2;
    if ( name == 'f' || name == 'h' || name == 'g' || name == 'y' || name == 'm' ) {
        chessCurrentCor = new Cor[ size ];
        for ( int i = 0; i < size; i++ )
            chessCurrentCor[ i ] = chessCorRecorder.chessPlace( name )[ i ];
    }
}