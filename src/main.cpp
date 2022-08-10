#include "../include/chessmain.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int gameBegin( chessMain* game );
void gameBoard( chessMain* game );

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
        if ( result == -1 )
            break;
    }
    curs_set( 1 );
    endwin();
    printf( "游戏结束\n" );
    return 0;
}

int gameBegin( chessMain* game ) {
    game->globalBoard->clean();
    game->globalBegin->display( 0 );
    int output = 0;
    while ( true ) {
        int input = game->getSelectorInput();
        switch ( input ) {
        case KEY_DOWN:
            game->globalBegin->display( input );
            break;
        case KEY_UP:
            game->globalBegin->display( input );
            break;
        case 'q':
            return -1;
        case KEY_ENTER:
            output = game->globalBegin->Selector();
            if ( output == 0 )
                return 0;
            if ( output == 1 )
                game->globalBegin->helpDisplay();
            if ( output == 2 )
                game->globalBegin->settingDisplay();
            if ( output == 3 )
                return -1;
            break;
        case 10:  // 在mac上代表enter键
            output = game->globalBegin->Selector();
            if ( output == 0 )
                return 0;
            if ( output == 1 )
                game->globalBegin->helpDisplay();
            if ( output == 2 )
                game->globalBegin->settingDisplay();
            if ( output == 3 )
                return -1;
            break;
        }
    }
}

void gameBoard( chessMain* game ) {
    game->globalBegin->clean();
    char chessName = game->chessReset();
    game->globalBoard->display( chessName );
    while ( true ) {
        int input = game->getBoardInput();
        if ( input == 'q' ) {
            game->chessEnd();
            break;
        } else if ( input == 'u' ) {
            game->chessUndo( chessName );
            game->globalBoard->display( chessName );
            continue;
        } else if ( input == 'r' ) {
            game->chessRedo( chessName );
            game->globalBoard->display( chessName );
            continue;
        } else if ( input == 'n' ) {
            char chessBoardNumber = game->getBoardInput();
            char temp = game->chessReset( chessBoardNumber );
            if ( temp != '\0' )
                chessName = temp;
            game->globalBoard->display( chessName );
            continue;
        } else if ( input == 'w' || input == 'a' || input == 's' || input == 'd' ) {
            game->chessMove( chessName, input );
            game->globalBoard->display( chessName );
        } else if ( input == KEY_LEFT || input == KEY_RIGHT || input == KEY_UP || input == KEY_DOWN ) {
            chessName = chessControl::chooseChess( input );
            game->globalBoard->display( chessName );
            continue;
        }
        if ( game->chessReachDestination() )
            break;
    }
}
