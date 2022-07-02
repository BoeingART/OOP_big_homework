#include "../../include/control/chessmoverecorder.h"
using namespace std;

chessMoveRecorder::chessMoveRecorder() {
    curStep = 0;
    if_UR = false;
    last_undo = false;
}

void chessMoveRecorder::pushChessMove( char& Name, char& Dir ) {
    if ( curStep < 0 )
        curStep = 0;
    steps temp( Name, Dir );
    stepList.push_back( temp );
    curStep++;
}

bool chessMoveRecorder::pullChessMoveLast( char& Name, char& Dir ) {
    if ( curStep <= 0 )
        return false;
    else {
        curStep--;
        Name = stepList[ curStep ].name;
        Dir = stepList[ curStep ].dir;
        return true;
    }
}

bool chessMoveRecorder::pullChessMoveNext( char& Name, char& Dir ) {
    if ( curStep >= stepList.size() )
        return false;
    else {
        Name = stepList[ curStep ].name;
        Dir = stepList[ curStep ].dir;
        curStep++;
        return true;
    }
}

void chessMoveRecorder::stepListClearPart() {
    for ( vector< steps >::iterator i = stepList.begin() + curStep; i != stepList.end(); ) {
        i = stepList.erase( i );
    }
    last_undo = false;
}

void chessMoveRecorder::stepListClear() {
    stepList.clear();
    curStep = 0;
}
