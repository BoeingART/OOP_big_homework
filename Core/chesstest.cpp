#include "chessmain.h"
#include "unistd.h"
#include <termios.h>
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
    chessMain test;
    char chessName = 'f';
    test.chessReset();
    chessControl::display( chessName );

    while ( true ) {
        usleep( 3000 );
        char name;
        name = scanKeyboard();
        printf( "\n" );
        if ( name == 'q' ) {
            test.chessEnd();
            break;
        } else if ( name == 'u' ) {
            test.chessUndo();
            chessControl::display();
            continue;
        } else if ( name == 'r' ) {
            test.chessRedu();
            chessControl::display();
            continue;
        } else if ( name == 'n' ) {
            char number = '0';
            number = scanKeyboard();
            if ( number == '0' )
                test.chessReset( "horizontal_knife" );
            else if ( number == '1' )
                test.chessReset( "neck_and_neck" );
            else if ( number == '2' )
                test.chessReset( "three_road" );
            else if ( number == '3' )
                test.chessReset( "station_troops" );
            else if ( number == '4' )
                test.chessReset( "left_and_right" );
            else if ( number == '~' )
                test.chessReset( "test" );
            else
                test.chessReset();
            chessControl::display();
            continue;
        } else if ( name == 'w' || name == 'a' || name == 's' || name == 'd' ) {
            cout << chessName << endl;
            if ( !test.chessMove( chessName, name ) ) {
                cout << "cannot move" << endl;
            };
            chessControl::display( chessName );
        } else if ( name == 'A' || name == 'B' || name == 'C' || name == 'D' ) {
            chessName = chessControl::chooseChess( name );
            chessControl::display( chessName );
        }
        if ( test.chessReachDestination() ) {
            break;
        }
    }
    return 0;
}
