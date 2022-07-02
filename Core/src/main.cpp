#include "../include/chessmain.h"
#include <ncurses.h>

using namespace std;

int main() {
    setlocale( LC_ALL, "" );  //同步终端字符库
    initscr();                // 初始化并进入curses 模式
    cbreak();                 // 行缓冲禁止，传递所有控制信息
    if ( !windowDetect() ) {
        printw( "窗口大小至少为：70 × 16" );
        refresh();
        getch();
        endwin();
        return 0;
    }
    chessMain* game = new chessMain();
    game->chessReset();
    char chessName = 'f';
    chessDisplay::display( chessName );
    while ( true ) {
        char input;
        input = scanKeyboard();
        printf( "\n" );
        if ( input == 'q' ) {
            game->chessEnd();
            break;
        } else if ( input == 'u' ) {
            game->chessUndo();
            chessDisplay::display();
            continue;
        } else if ( input == 'r' ) {
            game->chessRedo();
            chessDisplay::display();
            continue;
        } else if ( input == 'n' ) {
            char chessBoardNumber = scanKeyboard();
            game->chessReset( chessBoardNumber );
            chessDisplay::display();
            continue;
        } else if ( input == 'w' || input == 'a' || input == 's' || input == 'd' ) {
            game->chessMove( chessName, input );
            chessDisplay::display( chessName );
        } else if ( input == 'A' || input == 'B' || input == 'C' || input == 'D' ) {
            chessName = chessControl::chooseChess( input );
            chessDisplay::display( chessName );
        }
        if ( game->chessReachDestination() )
            break;
    }

    endwin();
    return 0;
}
