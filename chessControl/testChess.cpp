#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
#include <stdio.h>
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

void inputChessInfo(string name, char direction){
    Cor dir;
    switch (direction)
    {
    case 'u':
        dir = chessControl::dir_up;
        break;
    case 'd':
        dir = chessControl::dir_down;
        break;
    case 'l':
        dir = chessControl::dir_left;
        break;
    case 'r':
        dir = chessControl::dir_right;
        break;
    default:
        cout << "错误输入指令" << endl;
        cc.testPrint();
        return;
    }

    if(name == "cc"){
        cc.chessCorChange(dir);
        cc.testPrint();
    }else if(name == "f"){
        zf.chessCorChange(dir);
        zf.testPrint();
    }else if(name == "m"){
        mc.chessCorChange(dir);
        mc.testPrint();
    }else if(name == "g"){
        gy.chessCorChange(dir);
        gy.testPrint();
    }else if(name == "y"){
        zy.chessCorChange(dir);
        zy.testPrint();
    }else if(name == "h"){
        hz.chessCorChange(dir);
        hz.testPrint();
    }else if(name == "a"){
        bA.chessCorChange(dir);
        bA.testPrint();
    }else if(name == "b"){
        bB.chessCorChange(dir);
        bB.testPrint();
    }else if(name == "c"){
        bC.chessCorChange(dir);
        bC.testPrint();
    }else if(name == "d"){
        bD.chessCorChange(dir);
        bD.testPrint();
    }
}

int main(){
    cc.testPrint();
    while(true){
        string name;
        char dir;
        cout << "put name and direction: ";
        getline(cin, name, ' ').get(dir).get();
        if(name != "cc" && name != "zf" && name != "mc" && name != "gy" && name != "zy"
        && name != "hz" && name != "ba" && name != "bb" && name != "bc" && name != "bd"
        && name != "reset" && name != "end"){
            cout << "name is " << name << endl;
            cout << "error input in name" << endl;
            continue;
        }else if(dir != 'u' && dir != 'd' && dir != 'l' && dir != 'r'){
            cout << "direction is " << dir << endl;
            cout << "error input in direction" << endl;
            continue;
        }
        cout << "the input is: " << name << " " << dir << endl;
        if(name == "end"){
            break;
        }else if(name == "reset"){
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
            cc.testPrint();
            continue;
        }

        inputChessInfo(name, dir);
        if(cc.reachDestination()){
            cout << "到达世界最高城——理塘！" << endl;
            break;
        }
        cin.clear();
    }

    return 0;
}

