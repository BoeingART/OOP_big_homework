#include "../../include/display/chessbeginwindow.h"
#define SELECTED 99
#define TITLE 88

chessBeginWindow::chessBeginWindow() {
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    chessBeginWindow::beginWindow = newwin( row_number, column_number, size.ws_row / 2 - row_number / 2, size.ws_col / 2 - column_number / 2 );
    chessBeginWindow::selectWindow = newwin( se_row_number, se_col_number, size.ws_row / 2 - se_row_number / 2 + 3, size.ws_col / 2 - se_col_number / 2 );
    srand( time( 0 ) );
    init_pair( SELECTED, rand() % 7 + 1, COLOR_BLACK );
    init_pair( TITLE, rand() % 7 + 1, COLOR_BLACK );
}

void chessBeginWindow::display( int input ) {
    beginDisplay();
    selectDisplay( input );
}

void chessBeginWindow::beginDisplay() {
    // title
    wattron( beginWindow, COLOR_PAIR( TITLE ) );
    mvwprintw( beginWindow, 1, 0, gameTitle );
    wattroff( beginWindow, COLOR_PAIR( TITLE ) );

    // the edge
    mvwprintw( beginWindow, 0, 0, "╔" );
    mvwprintw( beginWindow, row_number - 1, 0, "╚" );
    mvwprintw( beginWindow, 0, column_number - 1, "╗" );
    mvwprintw( beginWindow, row_number - 1, column_number - 1, "╝" );

    for ( int i = 1; i < row_number - 1; i++ ) {
        mvwprintw( beginWindow, i, 0, "║" );
        mvwprintw( beginWindow, i, column_number - 1, "║" );
    }
    for ( int j = 1; j < column_number - 1; j++ ) {
        mvwprintw( beginWindow, 0, j, "═" );
        mvwprintw( beginWindow, row_number - 1, j, "═" );
    }
    wrefresh( beginWindow );
}

void chessBeginWindow::selectDisplay( int input ) {
    // edge
    mvwprintw( selectWindow, 0, 0, "╭" );
    mvwprintw( selectWindow, se_row_number - 1, 0, "╰" );
    mvwprintw( selectWindow, 0, se_col_number - 1, "╮" );
    mvwprintw( selectWindow, se_row_number - 1, se_col_number - 1, "╯" );
    for ( int i = 1; i < se_row_number - 1; i++ ) {
        mvwprintw( selectWindow, i, 0, "│" );
        mvwprintw( selectWindow, i, se_col_number - 1, "│" );
    }
    for ( int j = 1; j < se_col_number - 1; j++ ) {
        mvwprintw( selectWindow, 0, j, "─" );
        mvwprintw( selectWindow, se_row_number - 1, j, "─" );
    }

    // selector
    moveSelector( input );
    for ( int i = 0; i < 4; i++ ) {
        if ( i == selector ) {
            mvwprintw( selectWindow, 2 * i + 1, se_col_number / 2 - 6, ">" );
            wattron( selectWindow, A_BOLD );
            wattron( selectWindow, COLOR_PAIR( SELECTED ) );
        } else {
            mvwprintw( selectWindow, 2 * i + 1, se_col_number / 2 - 6, " " );
        }

        mvwprintw( selectWindow, 2 * i + 1, se_col_number / 2 - 4, gameSelections[ i ] );

        if ( i == selector ) {
            wattroff( selectWindow, A_BOLD );
            wattroff( selectWindow, COLOR_PAIR( SELECTED ) );
            mvwprintw( selectWindow, 2 * i + 1, se_col_number / 2 + 5, "<" );
        } else {
            mvwprintw( selectWindow, 2 * i + 1, se_col_number / 2 + 5, " " );
        }
    }

    wrefresh( selectWindow );
}

void chessBeginWindow::helpDisplay() {}

void chessBeginWindow::settingDisplay() {}

void chessBeginWindow::moveSelector( int input ) {
    if ( input == KEY_DOWN && selector < 3 )
        selector++;
    if ( input == KEY_UP && selector > 0 )
        selector--;
}

int chessBeginWindow::Selector() {
    return selector;
}

void chessBeginWindow::clean() {
    wclear( beginWindow );
    wclear( selectWindow );
}