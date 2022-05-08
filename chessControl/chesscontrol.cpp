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