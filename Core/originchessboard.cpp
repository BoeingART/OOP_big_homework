#include "originchessboard.h"
using namespace std;

// const globalConflict test[ 1 ][ 1 ] = { { { false, "hallo" } } };

chessCor::chessCor() {
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
    cout << "----------------" << endl;
    changeChessPlace( "horizontal_knife" );
    cout << "-----------------" << endl;
    cout << cc[ 0 ].x << " " << cc[ 0 ].y << endl;
    cout << "-----------------" << endl;
}

Cor* chessCor::chessPlace( std::string chessName ) {
    if ( chessName == "cc" )
        return cc;
    else if ( chessName == "zf" )
        return zf;
    else if ( chessName == "zy" )
        return zy;
    else if ( chessName == "gy" )
        return gy;
    else if ( chessName == "mc" )
        return mc;
    else if ( chessName == "hz" )
        return hz;
    else if ( chessName == "ba" )
        return ba;
    else if ( chessName == "bb" )
        return bb;
    else if ( chessName == "bc" )
        return bc;
    else if ( chessName == "bd" )
        return bd;
    else
        return nullptr;
}

globalConflict chessCor::chessBoard( std::string chessBoardName, int i, int j ) {
    if ( chessBoardName == "horizontal_knife" )
        return chessBoard_horizontal_knife[ i ][ j ];
    else
        return chessBoard_horizontal_knife[ i ][ j ];
}

void chessCor::changeChessPlace( std::string chessBoardName ) {
    globalConflict chessBoardTemp[ 4 ][ 5 ];
    if ( chessBoardName == "horizontal_knife" ) {
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                cout << chessBoard_horizontal_knife[ i ][ j ] << ", ";
                chessBoardTemp[ i ][ j ] = chessBoard_horizontal_knife[ i ][ j ];
            }
            cout << endl;
        }
    }
    cout << "XXXXXXXXXXXXXX" << endl;
    cout << chessBoardTemp[ 0 ][ 0 ].name;
    int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0, BA = 0, BB = 0, BC = 0, BD = 0;
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            if ( chessBoardTemp[ i ][ j ].name == "cc" ) {
                cout << CC << endl;
                cc[ CC++ ] = { i + 1, j + 1 };
                cout << CC << endl;
            } else if ( chessBoardTemp[ i ][ j ].name == "zf" )
                zf[ ZF++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "zy" )
                zy[ ZY++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "gy" )
                gy[ GY++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "mc" )
                mc[ MC++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "hz" )
                hz[ HZ++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "ba" )
                ba[ BA++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "bb" )
                bb[ BB++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "bc" )
                bc[ BC++ ] = { i + 1, j + 1 };
            else if ( chessBoardTemp[ i ][ j ].name == "bd" )
                bd[ BD++ ] = { i + 1, j + 1 };
        }
    }
}