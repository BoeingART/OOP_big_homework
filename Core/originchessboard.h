#ifndef ORIGINCHESSBOARD_H
#define ORIGINCHESSBOARD_H

#include "chessglobal.h"
#include "globalconflict.h"

/**
 * @brief 初始棋子坐标 \n(换行)
 * 类内记录了各种棋子的初始坐标，并同时记录了多种初始局面可以进行更换
 */
class originChessCor {
    Cor* cc;  //曹操
    Cor* zf;  //张飞
    Cor* hz;  //黄忠
    Cor* gy;  //关羽
    Cor* zy;  //赵云
    Cor* mc;  //马超
    Cor* ba;  //兵A
    Cor* bb;  //兵B
    Cor* bc;  //兵C
    Cor* bd;  //兵D

public:
    originChessCor();                                             //构造函数
    Cor* chessPlace( std::string chessName );                     //返回指定棋子名的坐标
    void changeChessPlace( std::string chessBoardName );          //改变初始棋盘局面
    globalConflict chessBoard( std::string name, int i, int j );  //返回棋盘指定位置的占用情况

    //横刀立马
    const globalConflict chessBoard_horizontal_knife[ 4 ][ 5 ] = {
        { { true, "zf" }, { true, "zf" }, { true, "mc" }, { true, "mc" }, { true, "ba" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bb" }, { false, "\0" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bc" }, { false, "\0" } },
        { { true, "zy" }, { true, "zy" }, { true, "hz" }, { true, "hz" }, { true, "bd" } } };

    //齐头并进
    const globalConflict chessBoard_neck_and_neck[ 4 ][ 5 ]{
        { { true, "zf" }, { true, "zf" }, { true, "ba" }, { true, "mc" }, { true, "mc" } },
        { { true, "cc" }, { true, "cc" }, { true, "bb" }, { true, "gy" }, { false, "\0" } },
        { { true, "cc" }, { true, "cc" }, { true, "bc" }, { true, "gy" }, { false, "\0" } },
        { { true, "zy" }, { true, "zy" }, { true, "bd" }, { true, "hz" }, { true, "hz" } } };

    //兵分三路
    const globalConflict chessBoard_three_road[ 4 ][ 5 ]{
        { { true, "ba" }, { true, "zf" }, { true, "zf" }, { true, "mc" }, { true, "mc" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bb" }, { false, "\0" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "bc" }, { false, "\0" } },
        { { true, "bd" }, { true, "zy" }, { true, "zy" }, { true, "hz" }, { true, "hz" } } };

    //吞并东路
    const globalConflict chessBoard_station_troops[ 4 ][ 5 ]{
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "mc" }, { true, "mc" } },
        { { true, "cc" }, { true, "cc" }, { true, "gy" }, { true, "hz" }, { true, "hz" } },
        { { true, "zf" }, { true, "zf" }, { true, "ba" }, { true, "bb" }, { false, "\0" } },
        { { true, "zy" }, { true, "zy" }, { true, "bc" }, { true, "bd" }, { false, "\0" } } };

    //左右逢源
    const globalConflict chessBoard_left_and_right[ 4 ][ 5 ]{
        { { true, "zf" }, { true, "zf" }, { false, "\0" }, { true, "ba" }, { true, "bb" } },
        { { true, "cc" }, { true, "cc" }, { true, "hz" }, { true, "hz" }, { true, "gy" } },
        { { true, "cc" }, { true, "cc" }, { true, "mc" }, { true, "mc" }, { true, "gy" } },
        { { true, "zy" }, { true, "zy" }, { false, "\0" }, { true, "bc" }, { true, "bd" } } };
};

#endif