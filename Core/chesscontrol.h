#ifndef CHESSCONTROL_H
#define CHESSCONTROL_H

#include "chessdirection.h"
#include "chessglobal.h"
#include "originchessboard.h"

class chessControl {
public:
    chessControl( std::string name = "none" );        //构造函数，通过name实例化对象
    ~chessControl();                                  //析构函数
    bool chessCorChange( chessDirection direction );  //移动棋子的函数，如果可以移动棋子则返回true，否则返回false
    void chessReset();                                //重置棋子
    static void chessBoardReset(std::string chessBoardName);                    //重置棋盘
    static void display();                            //控制栏输出
    const static int line = 4;                        //棋盘的列数
    const static int row = 5;                         //棋盘的行数

protected:
    int size;                                    //棋子的大小
    static globalConflict chessBoard[ 4 ][ 5 ];  //棋盘的占据情况
    //将corOccupied替换为chessBoard[4][5]，包含.occ(bool)和.name(string)

    static chessCor chessCorRecorder;
    std::string chessName;  //棋子的名称
    Cor* chessCurrentCor;   //棋子目前的坐标

    bool whetherOnSide( chessDirection direction );  //棋子是否处于棋盘边缘
    bool whetherMove( chessDirection& direction );   //棋子是否可以移动
    bool checkCor( int x, int y );                   //检查该坐标是否是棋子的坐标
};

#endif  // CHESSCONTROL_H
