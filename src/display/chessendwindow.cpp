#include "../../include/display/chessendwindow.h"

chessEndWindow::chessEndWindow() {
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    endWindow = newwin( 10, 10, 10, 10 );
    // endWindow = newwin( row_number, col_number, size.ws_row / 2 - row_number / 2, size.ws_col / 2 - col_number / 2 );
    keypad( endWindow, true );
}

char chessEndWindow::display() {
    // box( endWindow, 0, 0 );
    wprintw( endWindow, "hello, world" );
    wrefresh( endWindow );
    char temp = getch();
    return temp;
}