#include "chesscontrolsize4.h"
using namespace std;

chessControlSize4::chessControlSize4(std::string name): 
    chessControl(name)
{
    size = 4;
    chessCurrentCor = new Cor[size];
    if(name == "曹操"){
        chessName = "曹操";
        for(int i = 0; i < size; i++){
            chessCurrentCor[i] = cor_cc[i];
        }
        //chessCurrentCor[0].x = 2, chessCurrentCor[0].y = 1;//左上
        //chessCurrentCor[1].x = 3, chessCurrentCor[1].y = 1;//左下
        //chessCurrentCor[2].x = 2, chessCurrentCor[2].y = 2;//右上
        //chessCurrentCor[3].x = 3, chessCurrentCor[3].y = 2;//右下
    }else if(name == "test"){
        chessName = "test";
        chessCurrentCor[0].x = 1, chessCurrentCor[0].y = 1;//左上
        chessCurrentCor[1].x = 1, chessCurrentCor[1].y = 2;//左下
        chessCurrentCor[2].x = 2, chessCurrentCor[2].y = 1;//右上
        chessCurrentCor[3].x = 2, chessCurrentCor[3].y = 2;//右下
    }else if(name == "block1"){
        chessName = "block1";
        chessCurrentCor[0].x = 3, chessCurrentCor[0].y = 1;//左上
        chessCurrentCor[1].x = 3, chessCurrentCor[1].y = 2;//左下
        chessCurrentCor[2].x = 4, chessCurrentCor[2].y = 1;//右上
        chessCurrentCor[3].x = 4, chessCurrentCor[3].y = 2;//右下  
    }
    else{
        cerr << "error" << endl;
    }
    for(int i = 0; i < size; i++){
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
        //cout << i << ": " << size << endl;
    }
}

bool chessControlSize4::reachDestination(){
    if(chessName == "曹操"){
        if(this->chessCurrentCor[0].x == 2 && this->chessCurrentCor[0].y == 4){
            return true;
        }
    }
    //曹操的左上角到达(2, 4)时到达终点
    return false;
}