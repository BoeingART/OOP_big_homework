#include "chesscontrolsize4.h"
using namespace std;

chessControlSize4::chessControlSize4(std::string name): 
    chessControl(name)
{
    if(name == "曹操"){
        chessCurrentCor = new Cor[size];
        chessCurrentCor[0].x = 2, chessCurrentCor[0].y = 1;
        chessCurrentCor[1].x = 2, chessCurrentCor[1].y = 2;
        chessCurrentCor[2].x = 3, chessCurrentCor[2].y = 1;
        chessCurrentCor[3].x = 3, chessCurrentCor[3].y = 2;
    }else{
        cerr << "error" << endl;
    }
    for(int i = 0; i < size; i++){
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
        cout << i << ": " << size << endl;
    }
}
