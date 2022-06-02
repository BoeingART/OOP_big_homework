#include "chessmain.h"
#include "unistd.h"
using namespace std;

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
        }
        else if ( name == "undo" ) {
            test.chessUndo();
            continue;
        }
        else if ( name == "redo" ) {
            test.chessRedu();
            continue;
        }
        else if ( name == "reset" ) {
            test.chessReset();
            continue;
        }
        else if (
            name != "cc" && name != "f" && name != "m" && name != "g" && name != "y" && name != "h" && name != "a" && name != "b" && name != "c" && name != "d" && name != "reset" && name != "end"
            && name != "undo" && name != "redo" ) {
            cout << "name is " << name << endl;
            cout << "error input in name" << endl;
            continue;
        }
        else {
            cin >> dir;
            test.chessMove( name, dir );
        }
        if ( test.chessReachDestination() ) {
            break;
        }
    }
    return 0;
}