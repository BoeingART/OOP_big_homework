#include "../../include/control/chesscontrolsize4.h"
using namespace std;

chessControlSize4::chessControlSize4( char name )
    : chessControl( name ) {
    size = 4;
    chessCurrentCor = new Cor[ size ];
    for ( int i = 0; i < size; i++ )
        chessCurrentCor[ i ] = chessCorRecorder.chessPlace( name )[ i ];
}

bool chessControlSize4::reachDestination() {
    if ( chessName == 'c' ) {
        if ( this->chessCurrentCor[ 0 ].x == 2 && this->chessCurrentCor[ 0 ].y == 4 ) {
            return true;
        }
    }
    //曹操的左上角到达(2, 4)时到达终点
    return false;
}