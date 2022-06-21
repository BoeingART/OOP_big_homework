#include "chesscontrolsize2.h"
using namespace std;

chessControlSize2::chessControlSize2( std::string name )
    : chessControl( name ) {
    size = 2;
    if ( name == "zf" || name == "hz" || name == "gy" || name == "zy" || name == "mc" ) {
        chessCurrentCor = new Cor[ size ];
        for ( int i = 0; i < size; i++ )
            chessCurrentCor[ i ] = chessCorRecorder.chessPlace( name )[ i ];
        // if ( name == "zf" ) {
        //     for ( int i = 0; i < size; i++ ) {
        //         chessCurrentCor[ i ] = cor_zf[ i ];
        //     }
        // } else if ( name == "hz" ) {
        //     for ( int i = 0; i < size; i++ ) {
        //         chessCurrentCor[ i ] = cor_hz[ i ];
        //     }
        // } else if ( name == "gy" ) {
        //     for ( int i = 0; i < size; i++ ) {
        //         chessCurrentCor[ i ] = cor_gy[ i ];
        //     }
        // } else if ( name == "zy" ) {
        //     for ( int i = 0; i < size; i++ ) {
        //         chessCurrentCor[ i ] = cor_zy[ i ];
        //     }
        // } else if ( name == "mc" ) {
        //     for ( int i = 0; i < size; i++ ) {
        //         chessCurrentCor[ i ] = cor_mc[ i ];
        //     }
        // }
    }
}