#ifndef CHESSBEGINWINDOW
#define CHESSBEGINWINDOW

#include "../chessglobal.h"

class chessBeginWindow {
public:
    chessBeginWindow();
    void display( int input );

private:
    const int column_number = 5;
    const int row_number = 10;
    WINDOW* beginWindow;
};

#endif