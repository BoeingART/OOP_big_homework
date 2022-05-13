#include "chesscontrolsize1.h"
using namespace std;

chessControlSize1::chessControlSize1(std::string name): 
    chessControl(name)
{
    size = 1;
    if(name == "兵A" || name == "兵B" || name == "兵C" || name == "兵D"){
        chessCurrentCor = new Cor[1];
        if(name == "兵A"){
            chessName = "兵A";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_ba[i];
            }
            cout << "A"  << endl;
        }else if(name == "兵B"){
            chessName = "兵B";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_bb[i];
            }
        }else if(name == "兵C"){
            chessName = "兵C";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_bc[i];
            }
        }else if(name == "兵D"){
            chessName = "兵D";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_bd[i];
            }
        }
    }
    for(int i = 0; i < size; i++){
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
        cout << size << endl;
    }
}