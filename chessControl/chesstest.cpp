#include "chessmain.h"
using namespace std;



int main(){
    chessMain test;
    test.chessReset();
    while(true){
        chessControl::display();
        string name;
        char dir;
        cin >> name;
        if(name == "end"){
            break;
        }else if(name == "undo"){
            test.chessUndo();
            continue;
        }else if(name == "redo"){
            test.chessRedu();
            continue;
        }else if(name == "reset"){
            test.chessReset();
            continue;
        }else{
            cin >> dir;
            test.chessInput(name, dir);
        }
    }
    return 0;
}
/*


int main(){
    chessReset();
    //chessControl::display();
    Recorder.last_undo = false;
    while(true){
        chessControl::display();
        string name, empty;
        char dir;
        Recorder.if_UR = false;
        cout << "put name and direction: ";

        cin >> name;
        
        //system("reset");
        if(name != "cc" && name != "f" && name != "m" && name != "g" && name != "y"
        && name != "h" && name != "a" && name != "b" && name != "c" && name != "d"
        && name != "reset" && name != "end" && name != "undo" && name != "redo"){
            cout << "name is " << name << endl;
            cout << "error input in name" << endl;
            //chessControl::display();
            continue;
        }

        if(name == "end"){
            break;
        }else if(name == "reset"){
            chessReset();
            //chessControl::display();
            continue;
        }else if(name == "undo"){
            if(!Recorder.pullChessMoveLast(name, dir)){
                //cout << "cannot undo." << endl;
                //chessControl::display();
                continue;
            }else{
                Recorder.if_UR = true;
                //last_undo = true;
                Recorder.last_undo = true;
                dirChange(dir);
            }
            //cout << "the last time: " << name << " " << dir << endl;
        }else if(name == "redo"){
            if(!Recorder.pullChessMoveNext(name, dir)){
                //chessControl::display();
                continue;
            }else{
                Recorder.if_UR = true;
            }             
        }else{  
            if(Recorder.last_undo)
                Recorder.stepListClearPart();
            cin >> dir;
        }
        
        if(dir != 'u' && dir != 'd' && dir != 'l' && dir != 'r'){
            cout << "direction is " << dir << endl;
            cout << "error input in direction" << endl;
            //chessControl::display();
            continue;
        }
        //cout << "the input is: " << name << " " << dir << endl;
        //printf("\33[2J");

        inputChessInfo(name, dir, Recorder.if_UR);
        if(cc.reachDestination()){
            cout << "到达世界最高城——理塘！" << endl;
            break;
        }
        cin.clear();
    }

    return 0;
}
*/
