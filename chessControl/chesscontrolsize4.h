#include "chesscontrol.h"

class chessControlSize4: public chessControl
{
public:
    chessControlSize4(std::string name = "none");
    //~chessControlSize4();
    bool reachDestination();
};
