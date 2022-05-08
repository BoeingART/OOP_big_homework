#include "chesscontrol.h"
using namespace std;

int main(){
    chessControl cc("曹操");
    chessControl zf("张飞");
    chessControl hz("黄忠");
    chessControl gy("关羽");
    chessControl mc("马超");
    chessControl zy("赵云");
    chessControl bA("兵A");
    chessControl bB("兵B");
    chessControl bC("兵C");
    chessControl bD("兵D");
    cc.chessCorChange();
    cc.testPrint();
    return 0;
}