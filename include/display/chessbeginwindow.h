#ifndef CHESSBEGINWINDOW
#define CHESSBEGINWINDOW

#include "../chessglobal.h"

class chessBegin {
public:
    chessBegin();
    void display(int input);
    
private:
    WINDOW* chessBeginWindow;
};

#endif