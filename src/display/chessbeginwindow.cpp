#include "../../include/display/chessbeginwindow.h"

chessBeginWindow::chessBeginWindow() {
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    chessBeginWindow::beginWindow = newwin( column_number, row_number, size.ws_row / 2 - column_number / 2, size.ws_col / 2 - row_number / 2 );
}

void chessBeginWindow::display( int input ) {
    wrefresh( beginWindow );
}