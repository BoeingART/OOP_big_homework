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
    Cor* chessPlace( char chessName );                            //返回指定棋子名的坐标
    void changeChessPlace( std::string chessBoardName );          //改变初始棋盘局面
    globalConflict chessBoard( std::string name, int i, int j );  //返回棋盘指定位置的占用情况

    //横刀立马
    const globalConflict chessBoard_horizontal_knife[ 4 ][ 5 ] = {
        { { true, 'f' }, { true, 'f' }, { true, 'm' }, { true, 'm' }, { true, '1' } },
        { { true, 'c' }, { true, 'c' }, { true, 'g' }, { true, '2' }, { false, 'p' } },
        { { true, 'c' }, { true, 'c' }, { true, 'g' }, { true, '3' }, { false, 'q' } },
        { { true, 'y' }, { true, 'y' }, { true, 'h' }, { true, 'h' }, { true, '4' } } };

    //齐头并进
    const globalConflict chessBoard_neck_and_neck[ 4 ][ 5 ]{
        { { true, 'f' }, { true, 'f' }, { true, '1' }, { true, 'm' }, { true, 'm' } },
        { { true, 'c' }, { true, 'c' }, { true, '2' }, { true, 'g' }, { false, 'p' } },
        { { true, 'c' }, { true, 'c' }, { true, '3' }, { true, 'g' }, { false, 'q' } },
        { { true, 'y' }, { true, 'y' }, { true, '4' }, { true, 'h' }, { true, 'h' } } };

    //兵分三路
    const globalConflict chessBoard_three_road[ 4 ][ 5 ]{
        { { true, '1' }, { true, 'f' }, { true, 'f' }, { true, 'm' }, { true, 'm' } },
        { { true, 'c' }, { true, 'c' }, { true, 'g' }, { true, '2' }, { false, 'p' } },
        { { true, 'c' }, { true, 'c' }, { true, 'g' }, { true, '3' }, { false, 'q' } },
        { { true, '4' }, { true, 'y' }, { true, 'y' }, { true, 'h' }, { true, 'h' } } };

    //吞并东路
    const globalConflict chessBoard_station_troops[ 4 ][ 5 ]{
        { { true, 'c' }, { true, 'c' }, { true, 'g' }, { true, 'm' }, { true, 'm' } },
        { { true, 'c' }, { true, 'c' }, { true, 'g' }, { true, 'h' }, { true, 'h' } },
        { { true, 'f' }, { true, 'f' }, { true, '1' }, { true, '2' }, { false, 'p' } },
        { { true, 'y' }, { true, 'y' }, { true, '3' }, { true, '4' }, { false, 'q' } } };

    //左右逢源
    const globalConflict chessBoard_left_and_right[ 4 ][ 5 ]{
        { { true, 'f' }, { true, 'f' }, { false, 'p' }, { true, '1' }, { true, '2' } },
        { { true, 'c' }, { true, 'c' }, { true, 'h' }, { true, 'h' }, { true, 'g' } },
        { { true, 'c' }, { true, 'c' }, { true, 'm' }, { true, 'm' }, { true, 'g' } },
        { { true, 'y' }, { true, 'y' }, { false, 'q' }, { true, '3' }, { true, '4' } } };
};

#endif