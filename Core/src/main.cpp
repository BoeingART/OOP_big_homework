#include "../include/chessmain.h"
#include <ncurses.h>

using namespace std;

int main() {
    if ( !windowDetect() ) {
        printf( "窗口大小不够大\n" );
        return 0;
    }

    setlocale( LC_ALL, "" );  //同步终端字符库
    initscr();                // 初始化并进入curses 模式
    if ( has_colors() == false )
        return 0;
    noecho();
    start_color();
    cbreak();  // 行缓冲禁止，传递所有控制信息
    chessMain* game = new chessMain();
    keypad( game->globalDisplay->chessGameBoard, true );
    game->chessReset();
    char chessName = 'f';
    game->globalDisplay->test_display( "test..." );
    game->globalDisplay->display();
    while ( true ) {
        int input = wgetch( game->globalDisplay->chessGameBoard );
        if ( input == 'q' ) {
            game->chessEnd();
            break;
        } else if ( input == 'u' ) {
            game->chessUndo();
            game->globalDisplay->display();
            continue;
        } else if ( input == 'r' ) {
            game->chessRedo();
            game->globalDisplay->display();
            continue;
        } else if ( input == 'n' ) {
            char chessBoardNumber = scanKeyboard();
            game->chessReset( chessBoardNumber );
            game->globalDisplay->display();
            continue;
        } else if ( input == 'w' || input == 'a' || input == 's' || input == 'd' ) {
            game->chessMove( chessName, input );
            char temp[ 2 ] = { chessName, '\0' };
            game->globalDisplay->test_display( temp );
            game->globalDisplay->display( chessName );
        } else if ( input == KEY_LEFT || input == KEY_RIGHT || input == KEY_UP || input == KEY_DOWN ) {
            chessName = chessControl::chooseChess( input );
            char temp[ 2 ] = { chessName, '\0' };
            game->globalDisplay->test_display( temp );
            game->globalDisplay->display( chessName );
        } else if ( input == KEY_F( 2 ) )
            game->globalDisplay->test_display( "strange" );
        if ( game->chessReachDestination() )
            break;
    }

    endwin();
    return 0;
}
