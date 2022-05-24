#include "chessmoverecorder.h"
using namespace std;

chessMoveRecorder::chessMoveRecorder(){
    curStep = 0;
    if_UR = false;
    last_undo = false;
    //steps init = {"empty", '\0'};
    //chessMoveRecorder::stepList = {init};
}

void chessMoveRecorder::pushChessMove(string &Name, char &Dir){
    if(curStep < 0)
        curStep = 0;
    steps temp(Name, Dir);
    stepList.push_back(temp);
    //cout << "????" <<endl;
    //cout << "pushed " << stepList[curStep].name << " & " << stepList[curStep].dir << endl;
    curStep++;
    testPrint();
}

bool chessMoveRecorder::pullChessMoveLast(string &Name, char &Dir){
    //steps temp(Name, Dir);
    if(curStep <= 0){
        cout << "back to the origin state." << endl;
        cout << "cannot undo." << endl;
        return false;
    }else{
        curStep--;
        Name = stepList[curStep].name;
        Dir = stepList[curStep].dir;
        testPrint();
        return true;
    }
}

bool chessMoveRecorder::pullChessMoveNext(string &Name, char &Dir){
    if(curStep >= stepList.size()){
        cout << "back to the lastest state." << endl;
        cout << "cannot redo." << endl;
        return false;
    }else{
        
        Name = stepList[curStep].name;
        Dir = stepList[curStep].dir;
        curStep++;
        testPrint();
        return true;
    }

}

void chessMoveRecorder::stepListClearPart(){
    //cout << "??" << endl;
    for(vector<steps>::iterator i = stepList.begin() + curStep; i != stepList.end(); ){
        i = stepList.erase(i);
    }
    for(int i = curStep; i < stepList.size(); i++){
        //stepList[i].clear();
    }
}

void chessMoveRecorder::stepListClear(){
    stepList.clear();
    curStep = 0;
    cout << "stepList is cleared" << endl;
}

void chessMoveRecorder::testPrint(){
    for(int i = 0; i < stepList.size(); i++){
        cout << stepList[i].name << "->";
    }
    cout << endl;
}