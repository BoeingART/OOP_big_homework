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
}

chessControl::~chessControl(){
    delete[] chessCurrentCor;
    std::cout << "main:delete" << std::endl;
}

bool chessControl::chessCorChange(Cor direction){
    bool onSide = false;
    int judgeCor = 0;
    if(direction.x == -1 && direction.y == 0)//向左方
    {
        judgeCor = chessCurrentCor[0].x;
        //if(judgeCor <= 0 || )
    }
    else if(direction.x == 1 & direction.y == 0)//向右方
    {
        judgeCor = chessCurrentCor[size - 1].x;
    }
    else if(direction.x == 0 && direction.y == -1)//向下方
    {
        judgeCor = chessCurrentCor[0].y;
    }
    else if(direction.x == 0 && direction.y == 1)//向上方
    {
        judgeCor = chessCurrentCor[size - 1].y;
    }
    std::cout << "move" << std::endl;
    return onSide;
}

bool chessControl::reachDestination(){
    std::cout << "not reach destination" << std::endl;
    return false;
}

void chessControl::chessReset(){
    std::cout << "reseted" << std::endl;
}

void chessControl::recordChessMove(){
    std::cout << "chessMove" << std::endl;
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