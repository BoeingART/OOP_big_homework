#ifndef CHESSCONTROL_H
#define CHESSCONTROL_H

//#include "global.h"
#include <iostream>
#include <cstring>

struct Cor{
    int x;
    int y;
};
const Cor cor_cc[4] = {{2, 1}, {3, 1}, {2, 2}, {3, 2}};//曹操
const Cor cor_zf[2] = {{1, 1}, {1, 2}};//张飞
const Cor cor_hz[2] = {{1, 3}, {1, 4}};//黄忠
const Cor cor_gy[2] = {{2, 4}, {3, 4}};//关羽
const Cor cor_zy[2] = {{4, 3}, {4, 4}};//赵云
const Cor cor_mc[2] = {{4, 1}, {4, 2}};//马超
const Cor cor_ba[1] = {{1, 5}};//兵A
const Cor cor_bb[1] = {{2, 5}};//兵B
const Cor cor_bc[1] = {{3, 5}};//兵C
const Cor cor_bd[1] = {{4, 5}};//兵D

class chessControl
{
public:
    chessControl(std::string name = "none");//构造函数，通过name实例化对象
    ~chessControl();//析构函数
    bool chessCorChange(Cor direction);//移动棋子的函数，如果可以移动棋子则返回true，否则返回false
    //virtual bool reachDestination() = 0;//判断棋子是否达到终点
    void chessReset();//重置棋子
    void testPrint();//控制栏输出
    const static int line = 4;//棋盘的列数
    const static int row = 5;//棋盘的行数
    static Cor dir_left;//向左移动
    static Cor dir_right;//向右移动
    static Cor dir_up;//向上移动
    static Cor dir_down;//向下移动

protected:
    int size;//棋子的大小
    static bool corOccupied[4][5];//棋盘的占据情况
    static bool finishInit;//corOccupied是否被初始化
    std::string chessName;//棋子的名称
    Cor *chessCurrentCor;//棋子目前的坐标
    bool whetherOnSide(Cor direction);//棋子是否处于棋盘边缘
    bool whetherMove(Cor &direction);//棋子是否可以移动
    bool checkCor(int x, int y);//检查该坐标是否是棋子的坐标
};


#endif // CHESSCONTROL_H
