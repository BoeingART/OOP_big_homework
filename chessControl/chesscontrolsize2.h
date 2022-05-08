#include "chesscontrol.h"

class chessControlSize2: public chessControl
{
public:
    chessControlSize2(std::string name = "none");
    ~chessControlSize2();
private:
    const static int size = 4;
};
