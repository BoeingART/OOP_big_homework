#include "originchessboard.h"
using namespace std;

originChessCor::originChessCor() {
    cc = new Cor[ 4 ];
    zf = new Cor[ 2 ];
    zy = new Cor[ 2 ];
    gy = new Cor[ 2 ];
    mc = new Cor[ 2 ];
    hz = new Cor[ 2 ];
    ba = new Cor[ 1 ];
    bb = new Cor[ 1 ];
    bc = new Cor[ 1 ];
    bd = new Cor[ 1 ];
    changeChessPlace( "horizontal_knife" );
}

Cor* originChessCor::chessPlace( char chessName ) {
    if ( chessName == 'c' )
        return cc;
    else if ( chessName == 'f' )
        return zf;
    else if ( chessName == 'y' )
        return zy;
    else if ( chessName == 'g' )
        return gy;
    else if ( chessName == 'm' )
        return mc;
    else if ( chessName == 'h' )
        return hz;
    else if ( chessName == '1' )
        return ba;
    else if ( chessName == '2' )
        return bb;
    else if ( chessName == '3' )
        return bc;
    else if ( chessName == '4' )
        return bd;
    else
        return nullptr;
}

globalConflict originChessCor::chessBoard( std::string chessBoardName, int i, int j ) {
    if ( chessBoardName == "horizontal_knife" )
        return chessBoard_horizontal_knife[ i ][ j ];
    else if ( chessBoardName == "neck_and_neck" )
        return chessBoard_neck_and_neck[ i ][ j ];
    else if ( chessBoardName == "three_road" )
        return chessBoard_three_road[ i ][ j ];
    else if ( chessBoardName == "station_troops" )
        return chessBoard_station_troops[ i ][ j ];
    else if ( chessBoardName == "left_and_right" )
        return chessBoard_left_and_right[ i ][ j ];
    else if ( chessBoardName == "test" )
        return chessBoard_test[ i ][ j ];
    else
        return chessBoard_horizontal_knife[ i ][ j ];  //默认使用横刀立马局面
}

void originChessCor::changeChessPlace( std::string chessBoardName ) {
    globalConflict chessBoardTemp[ 4 ][ 5 ];
    if ( chessBoardName == "horizontal_knife" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                chessBoardTemp[ i ][ j ] = chessBoard_horizontal_knife[ i ][ j ];
            }
        }
    } else if ( chessBoardName == "neck_and_neck" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                chessBoardTemp[ i ][ j ] = chessBoard_neck_and_neck[ i ][ j ];
            }
        }
    } else if ( chessBoardName == "three_road" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                chessBoardTemp[ i ][ j ] = chessBoard_three_road[ i ][ j ];
            }
        }
    } else if ( chessBoardName == "station_troops" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                chessBoardTemp[ i ][ j ] = chessBoard_station_troops[ i ][ j ];
            }
        }
    } else if ( chessBoardName == "left_and_right" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                chessBoardTemp[ i ][ j ] = chessBoard_left_and_right[ i ][ j ];
            }
        }
    } else if ( chessBoardName == "test" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                chessBoardTemp[ i ][ j ] = chessBoard_test[ i ][ j ];
            }
        }
    }
    int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0, BA = 0, BB = 0, BC = 0, BD = 0;
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            if ( chessBoardTemp[ i ][ j ].name == 'c' ) {
                cout << CC << endl;
                cc[ CC++ ] = { i + 1, j + 1 };
                cout << CC << endl;
            } else if ( chessBoardTemp[ i ][ j ].name == 'f' )
                zf[ ZF++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == 'y' )
                zy[ ZY++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == 'g' )
                gy[ GY++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == 'm' )
                mc[ MC++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == 'h' )
                hz[ HZ++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == '1' )
                ba[ BA++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == '2' )
                bb[ BB++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == '3' )
                bc[ BC++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == '4' )
                bd[ BD++ ] = { i + 1, j + 1 };
        }
    }
}