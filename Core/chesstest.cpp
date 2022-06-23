#include "chessmain.h"

using namespace std;

int main() {
    printf( "\033[?25l" );  //隐藏光标
    chessMain test;         //棋子类
    char chessName = 'f';   //当前活跃的棋子名称
    test.chessReset();      //初始化棋盘并显示
    chessControl::display( chessName );
    while ( true ) {
        char input;
        input = scanKeyboard();
        if ( input == 'q' ) {
            test.chessEnd();
            break;
        } else if ( input == 'u' ) {
            test.chessUndo();
            chessControl::display();
            continue;
        } else if ( input == 'r' ) {
            test.chessRedu();
            chessControl::display();
            continue;
        } else if ( input == 'n' ) {
            char chessBoardNumber = scanKeyboard();
            test.chessReset( chessBoardNumber );
            chessControl::display();
            continue;
        } else if ( input == 'w' || input == 'a' || input == 's' || input == 'd' ) {
            test.chessMove( input );
            chessControl::display();
        } else if ( input == 'A' || input == 'B' || input == 'C' || input == 'D' ) {
            chessName = test.chessChoose( input );
            chessControl::display( chessName );
        }
        if ( test.chessReachDestination() ) {
            break;
        }
    }
    printf( "\033[?25h" );
    return 0;
}
