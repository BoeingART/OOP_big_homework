#ifndef CHESSDISPLAY
#define CHESSDISPLAY

#include "../chessglobal.h"
#include "../control/chesscontrol.h"

class chessDisplay {
public:
    chessDisplay();
    static void display( char chessName = '\0' );
    static void space_print( int number );
    static void enter_print( int number );
};

bool windowDetect();

#endif