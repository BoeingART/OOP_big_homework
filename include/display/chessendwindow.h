#ifndef CHESSENDWINDOW
#define CHESSENDWINDOW

#include "../chessglobal.h"

class chessEndWindow {
public:
    chessEndWindow();
    char display();

private:
    WINDOW* endWindow;
    const int col_number = 10;
    const int row_number = 10;
};

#endif
