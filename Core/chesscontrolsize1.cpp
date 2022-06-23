#include "chesscontrolsize1.h"
using namespace std;

chessControlSize1::chessControlSize1( char name )
    : chessControl( name ) {
    size = 1;
    if ( name == '1' || name == '2' || name == '3' || name == '4' ) {
        chessCurrentCor = new Cor[ size ];
        for ( int i = 0; i < size; i++ )
            chessCurrentCor[ i ] = chessCorRecorder.chessPlace( name )[ i ];
    }
}