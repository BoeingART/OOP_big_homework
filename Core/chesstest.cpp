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
        string name;
        char dir;
        cin >> name;
        if ( name == "end" ) {
            test.chessEnd();
            break;
        } else if ( name == "undo" ) {
            test.chessUndo();
            continue;
        } else if ( name == "redo" ) {
            test.chessRedu();
            continue;
        } else if ( name == "reset" ) {
            int number = 0;
            cin >> number;
            if ( number == 0 )
                test.chessReset( "horizontal_knife" );
            else if ( number == 1 )
                test.chessReset( "neck_and_neck" );
            else if ( number == 2 )
                test.chessReset( "three_road" );
            else if ( number == 3 )
                test.chessReset( "station_troops" );
            else if ( number == 4 )
                test.chessReset( "left_and_right" );
            else
                test.chessReset();
            continue;
        } else if (
            name != "cc" && name != "f" && name != "m" && name != "g" && name != "y" && name != "h" && name != "a" && name != "b" && name != "c" && name != "d" && name != "reset" && name != "end"
            && name != "undo" && name != "redo" ) {
            cout << "name is " << name << endl;
            cout << "error input in name" << endl;
            continue;
        } else {
            char dir = '\0';
            dir = scanKeyboard();
            test.chessMove( name, dir );
        }
        if ( test.chessReachDestination() ) {
            break;
        }
    }
    return 0;
}
