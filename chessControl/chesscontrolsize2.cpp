#include "chesscontrolsize2.h"
using namespace std;

chessControlSize2::chessControlSize2(std::string name): 
    chessControl(name)
{
    size = 2;
    if(name == "张飞" || name == "黄忠" || name == "关羽" || name == "赵云" || name == "马超"){
        chessCurrentCor = new Cor[size];
        if(name == "张飞"){
            chessName = "张飞";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_zf[i];
            }
        }else if(name == "黄忠"){
            chessName = "黄忠";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_hz[i];
            }
        }else if(name == "关羽"){
            chessName = "关羽";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_gy[i];
            }
        }else if(name == "赵云"){
            chessName = "赵云";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_zy[i];
            }
        }else if(name == "马超"){
            chessName = "马超";
            for(int i = 0; i < size; i++){
                chessCurrentCor[i] = cor_mc[i];
            }
        }
    }
    for(int i = 0; i < size; i++){
        cout << size << endl;
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
        cout << size << endl;
    }
}