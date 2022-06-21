#include "chesscontrolsize4.h"
using namespace std;

chessControlSize4::chessControlSize4( std::string name )
    : chessControl( name ) {
    size = 4;
    chessCurrentCor = new Cor[ size ];
    for ( int i = 0; i < size; i++ )
        chessCurrentCor[ i ] = chessCorRecorder.chessPlace( name )[ i ];
    // if ( name == "cc" ) {
    //     for ( int i = 0; i < size; i++ ) {
    //         chessCurrentCor[ i ] = cor_cc[ i ];
    //     }
    // } else {
    //     cerr << "error" << endl;
    // }
}

bool chessControlSize4::reachDestination() {
    if ( chessName == "cc" ) {
        if ( this->chessCurrentCor[ 0 ].x == 2 && this->chessCurrentCor[ 0 ].y == 4 ) {
            return true;
        }
    }
    //曹操的左上角到达(2, 4)时到达终点
    return false;
}