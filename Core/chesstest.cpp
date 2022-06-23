#include "chessmain.h"

using namespace std;



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
