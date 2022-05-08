#include "chesscontrol.h"
#include <iostream>

bool **chessControl::corOccupied = new bool*[4];

chessControl::chessControl(std::string name): chessName(name)
{
    if(name == "none"){
        std::cerr << "please put a name in" << std::endl;
        return;
    }
    if(name == "曹操"){
        size = 4;
        chessCurrentCor = new Cor[size];
        chessCurrentCor[0] = {2, 1};
        chessCurrentCor[1] = {2, 2};
        chessCurrentCor[2] = {3, 1};
        chessCurrentCor[3] = {3, 2};
    }else if(name == "张飞" || name == "黄忠" || name == "关羽" || name == "赵云" || name == "马超"){
        size = 2;
        chessCurrentCor = new Cor[size];
        if(name == "张飞"){
            chessCurrentCor[0] = {1, 1};
            chessCurrentCor[1] = {1, 2};
        }else if(name == "黄忠"){
            chessCurrentCor[0] = {1, 3};
            chessCurrentCor[1] = {1, 4};
        }else if(name == "关羽"){
            chessCurrentCor[0] = {2, 4};
            chessCurrentCor[1] = {3, 4};
        }else if(name == "赵云"){
            chessCurrentCor[0] = {4, 3};
            chessCurrentCor[1] = {4, 4};
        }else if(name == "马超"){
            chessCurrentCor[0] = {4, 2};
            chessCurrentCor[1] = {4, 1};
        }
    }else if(name == "兵A" || name == "兵B" || name == "兵C" || name == "兵D"){
        size = 1;
        chessCurrentCor = new Cor[1];
        if(name == "兵A"){
            chessCurrentCor[0] = {1, 5};
        }else if(name == "兵B"){
            chessCurrentCor[0] = {2, 5};
        }else if(name == "兵C"){
            chessCurrentCor[0] = {3, 5};
        }else if(name == "兵D"){
            chessCurrentCor[0] = {4, 5};
        }
    }

}
