#include "chessmoverecorder.h"
using namespace std;

chessMoveRecorder::chessMoveRecorder(){
    //steps init = {"empty", '\0'};
    //chessMoveRecorder::stepList = {init};
}

void chessMoveRecorder::pushChessMove(string &Name, char &Dir){
    cout << Name << " " << Dir << endl;
    steps temp(Name, Dir);
    stepList.push(temp);
    cout << "pushed " << stepList.top().name << " " << stepList.top().dir << endl;
}

bool chessMoveRecorder::pullChessMove(string &Name, char &Dir){
    steps temp(Name, Dir);
    if(stepList.empty()){
        cout << "back to the origin state." << endl;
        return false;
    }else{
        temp = stepList.top();
        Name = temp.name;
        Dir = temp.dir;
        stepList.pop();
        return true;
    }
}

void chessMoveRecorder::stepListClear(){
    while(!stepList.empty()){
        stepList.pop();
    }
    cout << "stepList is cleared" << endl;
}