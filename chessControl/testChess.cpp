#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
#include <stdlib.h>
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
        cin >> name;
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
        cin >> dir;
        inputChessInfo(name, dir);
        if(cc.reachDestination()){
            cout << "到达世界最高城——理塘！" << endl;
            break;
        }
        cin.clear();
        //system("clear");
    }

    // test.chessCorChange(chessControl::dir_left);
    // test.testPrint();
    // test.chessCorChange(chessControl::dir_right);
    // test.testPrint();
    // test.chessCorChange(chessControl::dir_up);
    // test.testPrint()
    // test.chessCorChange(chessControl::dir_down);
    // test.testPrint();
    return 0;
}

