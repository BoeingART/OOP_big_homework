#ifndef CHESSDISPLAY
#define CHESSDISPLAY

#include "../chessglobal.h"
#include "../control/chesscontrol.h"

class chessBoardWindow {
public:
    chessBoardWindow();
    void display( char chessName = 'c' );
    static void space_print( int number );
    static void enter_print( int number );
    int gameBoardInput();
    void clean();

private:
    WINDOW* gameBoardWindow;
    WINDOW* gameSideWindow;
    WINDOW* gameWinWindow;

private:
    const int row_times = 9;                             //行的间隔倍数 = 9
    const int col_times = 4;                             //列的间隔倍数= 4
    const int board_row_number = row_times * 4 + 1 + 4;  // 棋盘上行的宽度 = 41
    const int board_col_number = col_times * 5 + 1 + 2;  // 棋盘上列的宽度 = 23
    const int side_row_number = 15;                      //侧边栏行的宽度 = 15
    const int side_col_number = board_col_number;        // 侧边栏列的宽度 = 23

    bool boardLine[ 3 ][ 5 ];
    bool boardRow[ 4 ][ 4 ];

    int crossJudge( int x, int y );
    bool sameChess( int x1, int y1, int x2, int y2 );
    int chooseShowChess( int x, int y, int ( &chessNumber )[ 12 ] );
    void displayChess( char );
    void displayBoard();
    void displaySide();
    void highlightCurrentChess( char );

    bool highlight( char name, int x, int y );
    Cor getHighlight( char );
    void standardOn( char );
    void highlightOn( char );
    void standardOff( char );
    void highlightOff( char );
};

bool windowDetect();
bool GUI_init();

#endif