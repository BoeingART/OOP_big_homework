#include "chesscontrol.h"
using namespace std;

bool chessControl::finishInit = false;
bool chessControl::corOccupied[4][5] = {false};

Cor chessControl::dir_left = {-1, 0};
Cor chessControl::dir_right = {1, 0};
Cor chessControl::dir_up = {0, -1};
Cor chessControl::dir_down = {0, 1};

chessControl::chessControl(std::string name): chessName(name)
{
    if(!finishInit){
        for(int i = 0; i < line; i++){
            for(int j = 0; j < row; j++){
                corOccupied[i][j] = false;
                //cout << i << "-" << j << " ";
            }
            //cout << endl;
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
    bool onSide = whetherOnSide(direction);
    cout << "(" << direction.x << ")" <<"-" << "(" << direction.y << ")";
    if(onSide){
        cout << ": on the side, cannot move" << endl;
    }else{
        cout << ": not on the side, can move" << endl;
    }
    //std::cout << "move" << std::endl;
    if(onSide){
        return false;
    }
    return whetherMove(direction);
    
}

bool chessControl::whetherMove(Cor &direction){
    //首先删除该类中的位置占用信息，并将现在的坐标信息储存到一个新的坐标中
    Cor *tempCor = new Cor[size];
    for(int i = 0; i < size; i++){
        tempCor[i] = chessCurrentCor[i];
    }
    for(int i = 0; i < size; i++){
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = false;
    }
    //将棋子坐标向该方向移动

    for(int i = 0; i < size; i++){
        tempCor[i].x += direction.x;
        tempCor[i].y += direction.y;
    }

    //判断新的位置占用处是否有棋子被占用

    for(int i = 0; i < size; i++){
        if(corOccupied[tempCor[i].x - 1][tempCor[i].y - 1]){
            cout << "(" << tempCor[i].x << "," << tempCor[i].y << ")" <<"处重叠了" << endl;
            for(int j = 0; j < size; j++){
                corOccupied[chessCurrentCor[j].x - 1][chessCurrentCor[j].y - 1] = true;
            }
            return false;
            //如果有棋子占用则返回当前坐标，，同时将图中的信息进行添加，返回false
        }
    }
    for(int i = 0; i < size; i++){
        chessCurrentCor[i] = tempCor[i];
        corOccupied[chessCurrentCor[i].x - 1][chessCurrentCor[i].y - 1] = true;
    }
    
    
    //如果没有棋子占用则直接更新类中的坐标信息，并同时更新图的信息，返回true

    return true;
}

bool chessControl::whetherOnSide(Cor direction){
    bool onSide = false;
    if(direction.x == -1 && direction.y == 0)//向左方
    {
        if(chessCurrentCor[0].x <= 1)
            onSide = true;
    }
    else if(direction.x == 1 & direction.y == 0)//向右方
    {
        if(chessCurrentCor[size - 1].x >= line){
            onSide = true;
        }
    }
    else if(direction.x == 0 && direction.y == -1)//向上方
    {
        if(chessCurrentCor[0].y <= 1)
            onSide = true;
    }
    else if(direction.x == 0 && direction.y == 1)//向下方
    {
        if(chessCurrentCor[size - 1].y >= row)
            onSide = true;
    }
    return onSide;
}

bool chessControl::reachDestination(){
    std::cout << "not reach destination" << std::endl;
    return false;
}

void chessControl::chessReset(){
    std::cout << "reseted" << std::endl;
}

void chessControl::testPrint(){
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < line; j++){
            if(checkCor(j, i)){
                std::cout << "*";
            }else if(corOccupied[j][i] == true){
                std::cout << "·";
            }else{
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}

bool chessControl::checkCor(int x, int y){
    for(int i = 0; i < size; i++){
        if(x == chessCurrentCor[i].x - 1 && y == chessCurrentCor[i].y - 1){
            return true;
        }
    }
    return false;
}