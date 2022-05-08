#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
using namespace std;

int main(){
    chessControlSize4 cc("曹操");
    chessControlSize2 zf("张飞");
    chessControlSize2 hz("黄忠");
    chessControlSize2 gy("关羽");
    chessControlSize2 mc("马超");
    chessControlSize2 zy("赵云");
    chessControlSize1 bA("兵A");
    chessControlSize1 bB("兵B");
    chessControlSize1 bC("兵C");
    chessControlSize1 bD("兵D");
    Cor dir = {1, 0};
    cc.chessCorChange(dir);
    cc.testPrint();
    return 0;
}