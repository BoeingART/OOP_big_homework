#include "chesscontrolsize2.h"
using namespace std;

chessControlSize2::chessControlSize2(std::string name): 
    chessControl(name)
{
    if(name == "张飞" || name == "黄忠" || name == "关羽" || name == "赵云" || name == "马超"){
        chessCurrentCor = new Cor[size];
        if(name == "张飞"){
            chessCurrentCor[0].x = 1, chessCurrentCor[0].y = 1;
            chessCurrentCor[1].x = 1, chessCurrentCor[1].y = 2;
        }else if(name == "黄忠"){
            chessCurrentCor[0].x = 1, chessCurrentCor[0].y = 3;
            chessCurrentCor[1].x = 1, chessCurrentCor[1].y = 4;
        }else if(name == "关羽"){
            chessCurrentCor[0].x = 2, chessCurrentCor[0].y = 4;
            chessCurrentCor[1].x = 3, chessCurrentCor[1].y = 4;
        }else if(name == "赵云"){
            chessCurrentCor[0].x = 4, chessCurrentCor[0].y = 3;
            chessCurrentCor[1].x = 4, chessCurrentCor[1].y = 4;
        }else if(name == "马超"){
            chessCurrentCor[0].x = 4, chessCurrentCor[0].y = 2;
            chessCurrentCor[1].x = 4, chessCurrentCor[1].y = 1;
        }
    }
    for(int i = 0; i < size; i++){
        cout << size << endl;
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
        cout << size << endl;
    }
}