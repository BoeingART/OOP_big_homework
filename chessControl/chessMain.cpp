#include "chessMain.h"
using namespace std;

chessControlSize4 cc("cc");
chessControlSize2 zf("zf");
chessControlSize2 hz("hz");
chessControlSize2 gy("gy");
chessControlSize2 mc("mc");
chessControlSize2 zy("zy");
chessControlSize1 bA("ba");
chessControlSize1 bB("bb");
chessControlSize1 bC("bc");
chessControlSize1 bD("bd");

chessMoveRecorder Recorder;

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




void inputChessInfo(string name, char direction, bool if_UR){
    chessDirection dir(0, 0);
    //cout << "doing info" << endl;
    switch (direction)
    {
    case 'u':
        dir = dir_up;
        break;
    case 'd':
        dir = dir_down;
        break;
    case 'l':
        dir = dir_left;
        break;
    case 'r':
        dir = dir_right;
        break;
    default:
        cout << "错误输入指令" << endl;
        //chessControl::display();
        return;
    }
   
    bool if_move = true;
    if(name == "cc"){
        if_move = cc.chessCorChange(dir);
    }else if(name == "f"){
        if_move = zf.chessCorChange(dir);
    }else if(name == "m"){
        if_move = mc.chessCorChange(dir);
    }else if(name == "g"){
        if_move = gy.chessCorChange(dir);
    }else if(name == "y"){
        if_move = zy.chessCorChange(dir);
    }else if(name == "h"){
        if_move = hz.chessCorChange(dir);
    }else if(name == "a"){
        if_move = bA.chessCorChange(dir);
    }else if(name == "b"){
        if_move = bB.chessCorChange(dir);
    }else if(name == "c"){
        if_move = bC.chessCorChange(dir);
    }else if(name == "d"){
        if_move = bD.chessCorChange(dir);
    }
    if(!if_UR && if_move)
        Recorder.pushChessMove(name, direction);
    //chessControl::display();
}

void dirChange(char &Dir){
    switch (Dir)
    {
    case 'u':
        Dir = 'd';
        break;
    case 'd':
        Dir = 'u';
        break;
    case 'l':
        Dir = 'r';
        break;
    case 'r':
        Dir = 'l';
        break;
    default:
        break;
    }
}

void chessReset(){
    chessControl::chessBoardReset();
    cc.chessReset();
    zf.chessReset();
    mc.chessReset();
    gy.chessReset();
    zy.chessReset();
    hz.chessReset();
    bA.chessReset();
    bB.chessReset();
    bC.chessReset();
    bD.chessReset();
    Recorder.stepListClear();
}