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

    input = getchar();

    tcsetattr( 0, TCSANOW, &stored_settings );
    return input;
}

int main() {
    chessMain test;
    test.chessReset();
    while ( true ) {
        // usleep(200000);
        chessControl::display();
        char name;
        char dir;
        name = scanKeyboard();
        printf( "\n" );
        if ( name == 'q' ) {
            test.chessEnd();
            break;
        } else if ( name == 'u' ) {
            test.chessUndo();
            continue;
        } else if ( name == 'r' ) {
            test.chessRedu();
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
            else
                test.chessReset();
            continue;
        } else if ( name == 'c' || name == 'f' || name == 'm' || name == 'g' || name == 'y' || name == 'h' || name == '1' || name == '2' || name == '3' || name == '4' ) {
            chessControl::display( name );
            char dir = scanKeyboard();
            printf( "\n" );
            test.chessMove( name, dir );
        } else {
            if(name == 'A')
                printf( "震惊\n" );
            cout << "name is " << name << endl;
            cout << "error input in name" << endl;
            continue;
        }
        if ( test.chessReachDestination() ) {
            break;
        }
    }
    return 0;
}
