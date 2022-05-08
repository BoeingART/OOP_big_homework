#include "chesscontrol.h"

class chessControlSize1: public chessControl
{
public:
    chessControlSize1(std::string name = "none");
    ~chessControlSize1();
private:
    const static int size = 4;
};
