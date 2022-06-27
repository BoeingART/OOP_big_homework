#include "chessmain.h"

using namespace std;

int main() {
    if ( !windowDetect() ) {
        cerr << "窗口大小至少为：70 × 16" << endl;
        return 0;
    }
    printf( "\033[?25l" );
    chessMain test;
    test.chessReset();
    char chessName = 'f';
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
            test.chessRedo();
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
