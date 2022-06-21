#include "chesscontrolsize1.h"
using namespace std;

chessControlSize1::chessControlSize1( std::string name )
    : chessControl( name ) {
    size = 1;
    if ( name == "ba" || name == "bb" || name == "bc" || name == "bd" ) {
        chessCurrentCor = new Cor[ 1 ];
        if ( name == "ba" ) {
            for ( int i = 0; i < size; i++ ) {
                chessCurrentCor[ i ] = cor_ba[ i ];
            }
        } else if ( name == "bb" ) {
            for ( int i = 0; i < size; i++ ) {
                chessCurrentCor[ i ] = cor_bb[ i ];
            }
        } else if ( name == "bc" ) {
            for ( int i = 0; i < size; i++ ) {
                chessCurrentCor[ i ] = cor_bc[ i ];
            }
        } else if ( name == "bd" ) {
            for ( int i = 0; i < size; i++ ) {
                chessCurrentCor[ i ] = cor_bd[ i ];
            }
        }
    }
}