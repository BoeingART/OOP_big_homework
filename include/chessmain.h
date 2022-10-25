#ifndef CHESSMAIN_H
#define CHESSMAIN_H

#include "chessglobal.h"
#include "control/chesscontrol.h"
#include "control/chesscontrolsize1.h"
#include "control/chesscontrolsize2.h"
#include "control/chesscontrolsize4.h"
#include "control/chessdirection.h"
#include "control/chessmoverecorder.h"
#include "display/chessbeginwindow.h"
#include "display/chessboardwindow.h"
#include "display/chessendwindow.h"
#include "solute/chesssolute.h"

class chessMain {
public:
    chessMain();
    chessMain( char test );
    ~chessMain();
    void showExitWindow();
    void chessHighLight( const char& name );                                     //输出高亮棋子
    bool chessMove( char name, char directionn );                                //移动棋子
    char chessReset( char chessBoardNumber = '0' );                              //重置棋盘
    int chessChoose( int input );                                                //选择棋子
    char chessRedo( char& name );                                                //重做上一步
    char chessUndo( char& name );                                                //撤回上一步
    bool chessReachDestination();                                                //棋子到达终点
    bool chessEnd();                                                             //游戏结束
    void chessSelect( int input );                                               //在开始界面选择棋子
    bool showTips();                                                             //当到达终点后展示下一步提示~
    static const char* chessBoardInfo( const int i, const int j, const int n );  //获取棋盘上第i行第j列的元素信息
    static int col();                                                            //棋盘的列数 = 4
    static int row();                                                            //棋盘的行数 = 5

    chessBeginWindow* globalBegin;
    chessBoardWindow* globalBoard;
    chessSolute* globalSolute;
    chessEndWindow* end;

    int getSelectorInput();
    int getSettingInput();
    int getHelpInput();
    int getBoardInput();

private:
    bool inputChessInfo( char name, char direction );  //输入棋子信息
    void dirChange( char& Dir );                       //改变棋子方向（主要是undo时）
    char chessName;
    Cor getFocusCor( char );
    chessControlSize4* cc;
    chessControlSize2* zf;
    chessControlSize2* hz;
    chessControlSize2* gy;
    chessControlSize2* mc;
    chessControlSize2* zy;
    chessControlSize1* bA;
    chessControlSize1* bB;
    chessControlSize1* bC;
    chessControlSize1* bD;
    chessMoveRecorder* Recorder;
};

int gameBegin( chessMain* game );
void gameBoard( chessMain* game );

#endif