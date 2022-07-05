#include "../include/chessmain.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {
    if ( !windowDetect() ) {
        printf( "窗口大小不够大\n" );
        return 0;
    }
    char temp;
    cin >> temp;
    if ( temp == 't' ) {
        chessMain* game = new chessMain( temp );
        getchar();
        return 0;
    }
    if ( !GUI_init() )
        return 0;
    chessMain* game = new chessMain();
    game->chessReset();
    char chessName = 'f';
    game->globalDisplay->display( 'c' );
    while ( true ) {
        int input = game->getInput();
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
            char chessBoardNumber = game->getInput();
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
        }
        if ( game->chessReachDestination() )
            break;
    }
    curs_set( 1 );
    endwin();
    return 0;
}
