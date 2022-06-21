#ifndef ORIGINCHESSBOARD_H
#define ORIGINCHESSBOARD_H

#include "chessglobal.h"
#include "vector"

// const globalConflict originChessBoard[ 4 ][ 5 ] = {
//     ( { true, "zf" }, ( true, "zf" ), ( true, "hz" ), ( true, "hz" ), ( true, "ba" ) ), ( ( true, "cc" ), ( true, "cc" ), ( false, "\0" ), ( true, "gy" ), ( true, "bb" ) ),
//     ( ( true, "cc" ), ( true, "cc" ), ( false, "\0" ), ( true, "gy" ), ( true, "bc" ) ), ( ( true, "mc" ), ( true, "mc" ), ( true, "zy" ), ( true, "zy" ), ( true, "bd" ) ) };

// const Cor cor_cc[ 4 ] = { { 2, 1 }, { 3, 1 }, { 2, 2 }, { 3, 2 } };  //曹操
// const Cor cor_zf[ 2 ] = { { 1, 1 }, { 1, 2 } };                      //张飞
// const Cor cor_hz[ 2 ] = { { 1, 3 }, { 1, 4 } };                      //黄忠
// const Cor cor_gy[ 2 ] = { { 2, 4 }, { 3, 4 } };                      //关羽
// const Cor cor_zy[ 2 ] = { { 4, 3 }, { 4, 4 } };                      //赵云
// const Cor cor_mc[ 2 ] = { { 4, 1 }, { 4, 2 } };                      //马超
// const Cor cor_ba[ 1 ] = { { 1, 5 } };                                //兵A
// const Cor cor_bb[ 1 ] = { { 2, 5 } };                                //兵B
// const Cor cor_bc[ 1 ] = { { 3, 5 } };                                //兵C
// const Cor cor_bd[ 1 ] = { { 4, 5 } };                                //兵D

class chessCor {
    Cor* cc;
    Cor* zf;
    Cor* hz;
    Cor* gy;
    Cor* zy;
    Cor* mc;
    Cor* ba;
    Cor* bb;
    Cor* bc;
    Cor* bd;

public:
    chessCor();
    Cor* chessPlace( std::string chessName );
    void changeChessPlace( std::string chessBoardName );
    globalConflict chessBoard( std::string name, int i, int j );
    const globalConflict chessBoard_horizontal_knife[ 4 ][ 5 ] = {
        { { true, "zf" }, { true, "zf" }, { true, "mc" }, { true, "mc" }, { true, "ba" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bb" }, { false, "\0" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bc" }, { false, "\0" } },
        { { true, "zy" }, { true, "zy" }, { true, "hz" }, { true, "hz" }, { true, "bd" } } };
    const globalConflict chessBoard_neck_and_neck[ 4 ][ 5 ]{
        { { true, "zf" }, { true, "zf" }, { true, "ba" }, { true, "mc" }, { true, "mc" } },
        { { true, "cc" }, { true, "cc" }, { true, "bb" }, { true, "gy" }, { false, "\0" } },
        { { true, "cc" }, { true, "cc" }, { true, "bc" }, { true, "gy" }, { false, "\0" } },
        { { true, "zy" }, { true, "zy" }, { true, "bd" }, { true, "hz" }, { true, "hz" } } };
    const globalConflict chessBoard_three_road[ 4 ][ 5 ]{
        { { true, "ba" }, { true, "zf" }, { true, "zf" }, { true, "mc" }, { true, "mc" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bb" }, { false, "\0" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bc" }, { false, "\0" } },
        { { true, "ba" }, { true, "zy" }, { true, "zy" }, { true, "hz" }, { true, "hz" } } };
    const globalConflict chessBoard_station_troops[ 4 ][ 5 ]{
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "mc" }, { true, "mc" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "hz" }, { false, "hz" } },
        { { true, "zf" }, { true, "zf" }, { true, "ba" }, { true, "bb" }, { false, "\0" } },
        { { true, "zy" }, { true, "zy" }, { true, "bc" }, { true, "bd" }, { false, "\0" } } };
    const globalConflict chessBoard_left_and_right[ 4 ][ 5 ]{
        { { true, "zf" }, { true, "zf" }, { false, "\0" }, { true, "ba" }, { true, "bb" } },
        { { true, "cc" }, { true, "cc" }, { true, "hz" }, { true, "hz" }, { true, "gy" } },
        { { true, "cc" }, { true, "cc" }, { true, "mc" }, { true, "mc" }, { true, "gy" } },
        { { true, "zy" }, { true, "zy" }, { false, "\0" }, { true, "bc" }, { true, "bd" } } };
};

#endif