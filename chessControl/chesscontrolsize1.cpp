#include "chesscontrolsize1.h"
using namespace std;

chessControlSize1::chessControlSize1(std::string name): 
    chessControl(name)
{
    size = 1;
    if(name == "兵A" || name == "兵B" || name == "兵C" || name == "兵D"){
        chessCurrentCor = new Cor[1];
        if(name == "兵A"){
            chessCurrentCor[0].x = 1, chessCurrentCor[0].y = 5;
            cout << "A"  << endl;
        }else if(name == "兵B"){
            chessCurrentCor[0].x = 2, chessCurrentCor[0].y = 5;
        }else if(name == "兵C"){
            chessCurrentCor[0].x = 3, chessCurrentCor[0].y = 5;
        }else if(name == "兵D"){
            chessCurrentCor[0].x = 4, chessCurrentCor[0].y = 5;
        }
    }
    for(int i = 0; i < size; i++){
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
        cout << size << endl;
    }
}