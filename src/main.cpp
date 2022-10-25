#include "../include/chessmain.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {
    if ( !windowDetect() ) {
        printf( "窗口大小不够大\n" );
        return 0;
    }
    if ( !GUI_init() ) {
        printf( "无法启动图形化界面\n" );
        return 0;
    }
    chessMain* game = new chessMain();
    while ( true ) {
        int result = gameBegin( game );
        if ( result == 0 )
            gameBoard( game );
        if ( result == -1 ) {
            break;
        }
    }
    curs_set( 1 );
    endwin();
    printf( "游戏结束\n" );
    return 0;
}
