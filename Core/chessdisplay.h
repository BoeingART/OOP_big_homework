#ifndef CHESSDISPLAY
#define CHESSDISPLAY

#include "chessmain.h"

class chessDisplay {
public:
    static void display( char chessName = '\0' );
    static void space_print( int number );
    static void enter_print( int number );
private:

};

bool windowDetect();

#endif