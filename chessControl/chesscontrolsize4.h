#include "chesscontrol.h"

class chessControlSize4: public chessControl
{
public:
    chessControlSize4(std::string name = "none");
    //~chessControlSize4();
private:
    const static int size = 4;
};
