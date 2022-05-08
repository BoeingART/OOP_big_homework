#include "chesscontrol.h"
using namespace std;

bool chessControl::finishInit = false;
bool chessControl::corOccupied[4][5] = {false};

chessControl::chessControl(std::string name): chessName(name)
{
    if(!finishInit){
        for(int i = 0; i < line; i++){
            for(int j = 0; j < row; j++){
                corOccupied[i][j] = false;
                cout << i << "-" << j << " ";
            }
            cout << endl;
        }
        finishInit = true;
    }
    if(name == "none"){
        std::cerr << "please put a name in" << std::endl;
        return;
    }
    if(name == "曹操"){
        size = 4;
        chessCurrentCor = new Cor[size];
        chessCurrentCor[0].x = 2, chessCurrentCor[0].y = 1;
        chessCurrentCor[1].x = 2, chessCurrentCor[1].y = 2;
        chessCurrentCor[2].x = 3, chessCurrentCor[2].y = 1;
        chessCurrentCor[3].x = 3, chessCurrentCor[3].y = 2;
    }else if(name == "张飞" || name == "黄忠" || name == "关羽" || name == "赵云" || name == "马超"){
        size = 2;
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
    }else if(name == "兵A" || name == "兵B" || name == "兵C" || name == "兵D"){
        size = 1;
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

chessControl::~chessControl(){
    std::cout << "delete" << std::endl;
}

bool chessControl::chessCorChange(){
    std::cout << "move" << std::endl;
    return true;
}

bool chessControl::reachDestination(){
    std::cout << "not reach destination" << std::endl;
    return false;
}

void chessControl::chessReset(){
    std::cout << "reseted" << std::endl;
}

void chessControl::recordChessMove(int direction){
    std::cout << "chessMive" << std::endl;
}

void chessControl::testPrint(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < line; j++){
            if(corOccupied[j][i] == true){
                std::cout << "*";
            }else{
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}