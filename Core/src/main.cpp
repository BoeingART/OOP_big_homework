#include "../include/chessmain.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {

    if ( !windowDetect() ) {
        printf( "窗口大小不够大\n" );
        return 0;
    }
    if ( !GUI_init() )
        return 0;
    chessMain* game = new chessMain();
    char chessName = game->chessReset();
    game->globalDisplay->display( chessName );
    while ( true ) {
        int input = game->getInput();
        if ( input == 'q' ) {
            game->chessEnd();
            break;
        } else if ( input == 'u' ) {
            game->chessUndo( chessName );
            game->globalDisplay->display( chessName );
            continue;
        } else if ( input == 'r' ) {
            game->chessRedo( chessName );
            game->globalDisplay->display( chessName );
            continue;
        } else if ( input == 'n' ) {
            char chessBoardNumber = game->getInput();
            char temp = game->chessReset( chessBoardNumber );
            if ( temp != '\0' )
                chessName = temp;
            game->globalDisplay->display( chessName );
            continue;
        } else if ( input == 'w' || input == 'a' || input == 's' || input == 'd' ) {
            game->chessMove( chessName, input );
            game->globalDisplay->display( chessName );
        } else if ( input == KEY_LEFT || input == KEY_RIGHT || input == KEY_UP || input == KEY_DOWN ) {
            chessName = chessControl::chooseChess( input );
            game->globalDisplay->display( chessName );
            continue;
        }
        if ( game->chessReachDestination() )
            break;
    }
    curs_set( 1 );
    endwin();
    return 0;
}
