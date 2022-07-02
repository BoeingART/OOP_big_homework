#ifndef CHESSDISPLAY
#define CHESSDISPLAY

#include "../chessglobal.h"
#include "../control/chesscontrol.h"

class chessDisplay {
public:
    chessDisplay();
    void test_display( char* out ) {
        werase( chessGameHelp );
        init_pair( 1, COLOR_RED, COLOR_WHITE );
        attron( COLOR_PAIR( 1 ) );
        wprintw( chessGameHelp, out );
        attroff( COLOR_PAIR( 1 ) );
        wrefresh( chessGameHelp );
    }
    void display( char chessName = '\0' );
    static void space_print( int number );
    static void enter_print( int number );

    WINDOW* chessGameBoard;
    WINDOW* chessGameControl;
    WINDOW* chessGameHelp;
};

bool windowDetect();

#endif