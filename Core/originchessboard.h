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
        { { true, "zf" }, { true, "zf" }, { true, "hz" }, { true, "hz" }, { true, "ba" } },
        { { true, "cc" }, { true, "cc" }, { false, "\0" }, { true, "gy" }, { true, "bb" } },
        { { true, "cc" }, { true, "cc" }, { false, "\0" }, { true, "gy" }, { true, "bc" } },
        { { true, "mc" }, { true, "mc" }, { true, "zy" }, { true, "zy" }, { true, "bd" } } };
};

#endif