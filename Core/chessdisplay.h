#ifndef CHESSDISPLAY
#define CHESSDISPLAY

#include "chesscontrol.h"

class chessDisplay : public chessControl {
public:
    static void display( char chessName = '\0' );
    static void space_print( int number );
    static void enter_print( int number );
};

bool windowDetect();

#endif