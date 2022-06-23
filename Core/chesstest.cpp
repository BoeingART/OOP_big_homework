#include "chessmain.h"

using namespace std;

int scanKeyboard() {
    int input;
    struct termios new_settings;
    struct termios stored_settings;
    tcgetattr( 0, &stored_settings );
    new_settings = stored_settings;
    new_settings.c_lflag &= ( ~ICANON );
    new_settings.c_cc[ VTIME ] = 0;
    tcgetattr( 0, &stored_settings );
    new_settings.c_cc[ VMIN ] = 1;
    tcsetattr( 0, TCSANOW, &new_settings );
    system( "stty -echo" );
    input = getchar();
    system( "stty echo" );
    tcsetattr( 0, TCSANOW, &stored_settings );
    return input;
}

int main() {
    printf( "\033[?25l" );
    chessMain test;
    char chessName = 'f';
    test.chessReset();
    chessDisplay::display( chessName );
    while ( true ) {
        char input;
        input = scanKeyboard();
        printf( "\n" );
        if ( input == 'q' ) {
            test.chessEnd();
            break;
        } else if ( input == 'u' ) {
            test.chessUndo();
            chessDisplay::display();
            continue;
        } else if ( input == 'r' ) {
            test.chessRedu();
            chessDisplay::display();
            continue;
        } else if ( input == 'n' ) {
            char chessBoardNumber = scanKeyboard();
            test.chessReset( chessBoardNumber );
            chessDisplay::display();
            continue;
        } else if ( input == 'w' || input == 'a' || input == 's' || input == 'd' ) {
            test.chessMove( chessName, input );
            chessDisplay::display( chessName );
        } else if ( input == 'A' || input == 'B' || input == 'C' || input == 'D' ) {
            chessName = chessControl::chooseChess( input );
            chessDisplay::display( chessName );
        }
        if ( test.chessReachDestination() )
            break;
    }
    printf( "\033[?25h" );
    printf( "\033c" );
    return 0;
}
