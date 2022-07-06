#ifndef CHESSDISPLAY
#define CHESSDISPLAY

#include "../chessglobal.h"
#include "../control/chesscontrol.h"

class chessDisplay {
public:
    chessDisplay();
    void test_display( char* out ) {
        werase( chessGameHelp );
    }
    void display( char chessName = 'c' );
    static void space_print( int number );
    static void enter_print( int number );
    int gameBoardInput();

    WINDOW* chessGameBoard;
    WINDOW* chessGameControl;
    WINDOW* chessGameHelp;

private:
    const int row_times = 9;
    const int column_times = 4;

    const int row_number = row_times * 4 + 1 + 4;
    const int column_number = column_times * 5 + 1 + 2;

    bool boardLine[ 3 ][ 5 ];
    bool boardRow[ 4 ][ 4 ];

    int crossJudge( int x, int y );
    bool sameChess( int x1, int y1, int x2, int y2 );
    int chooseShowChess( int x, int y, int ( &chessNumber )[ 12 ] );
    void displayChess( char );
    void highlightCurrentChess( char );
    void displayBoard();
    bool highlight( char name, int x, int y );
    Cor getHighlight( char );
};

bool windowDetect();
bool GUI_init();

#endif