#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
using namespace std;


chessControlSize4 cc("曹操");
chessControlSize2 zf("张飞");
    // chessControlSize2 hz("黄忠");
    // chessControlSize2 gy("关羽");
    // chessControlSize2 mc("马超");
    // chessControlSize2 zy("赵云");
    // chessControlSize1 bA("兵A");
    // chessControlSize1 bB("兵B");
    // chessControlSize1 bC("兵C");
    // chessControlSize1 bD("兵D");

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
        return;
    }

    if(name == "cc"){
        cc.chessCorChange(dir);
        cc.testPrint();
    }else if(name == "zf"){
        zf.chessCorChange(dir);
        zf.testPrint();
    }
}

int main(){

    //chessControlSize4 cc("曹操");
    // chessControlSize2 zf("张飞");
    // chessControlSize2 hz("黄忠");
    // chessControlSize2 gy("关羽");
    // chessControlSize2 mc("马超");
    // chessControlSize2 zy("赵云");
    // chessControlSize1 bA("兵A");
    // chessControlSize1 bB("兵B");
    // chessControlSize1 bC("兵C");
    // chessControlSize1 bD("兵D");
    
    // test.testPrint();
    // test.chessCorChange(chessControl::dir_down);
    
    // test.testPrint();
    // test.chessCorChange(chessControl::dir_down);
    // for(int i = 0; i < 2; i++){
    //     test.chessCorChange(chessControl::dir_right);
    // }
    // test.testPrint();
    // test.chessCorChange(chessControl::dir_up);
    // test.chessCorChange(chessControl::dir_down);
    // test.chessCorChange(chessControl::dir_down);
    // test.testPrint();
    
    while(true){
        string name;
        char dir;
        cin >> name >> dir;
        if(dir == 'e'){
            break;
        }
        inputChessInfo(name, dir);
        if(cc.reachDestination()){
            break;
        }
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

