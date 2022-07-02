#ifndef CHESSCONTROL_H
#define CHESSCONTROL_H

#include "chessdirection.h"
#include "../chessglobal.h"
#include "originchessboard.h"

//棋子控制类
class chessControl {
public:
    chessControl( char name = 'n' );                               //构造函数，通过name实例化对象
    ~chessControl();                                               //析构函数
    bool chessCorChange( chessDirection direction );               //移动棋子的函数，如果可以移动棋子则返回true，否则返回false
    void chessReset();                                             //重置棋子
    static void chessBoardReset( std::string chessBoardName );     //重置棋盘
    static char chooseChess( char dir );                           //选择棋子
    const static int line = 4;                                     //棋盘的列数
    const static int row = 5;                                      //棋盘的行数
    static chessConflict chessCurrentComplextion( int i, int j );  //返回棋盘当前的局面

protected:
    int size;                                //棋子的大小
    static originChessCor chessCorRecorder;  //初始棋子坐标
    char chessName;                          //棋子的名称
    Cor* chessCurrentCor;                    //棋子目前的坐标
    static void namedSpace();
    static chessBoard chessComplexion;               //棋盘的占据情况
    bool whetherOnSide( chessDirection direction );  //棋子是否处于棋盘边缘
    bool whetherMove( chessDirection& direction );   //棋子是否可以移动
    bool checkCor( int x, int y );                   //检查该坐标是否是棋子的坐标

private:
    static Cor currentFocus;
    static bool onside( Cor cor, char dir );
};

#endif  // CHESSCONTROL_H
