#ifndef CHESSCONTROL4_H
#define CHESSCONTROL4_H


#include "chesscontrol.h"

class chessControlSize4: public chessControl
{
public:
    chessControlSize4(std::string name = "none");
    bool reachDestination();
};

#endif
