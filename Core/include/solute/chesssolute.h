#include "../control/chesscontrol.h"

struct Results {
    char chessName;
    int direction;
};

class chessSolute {
public:
    chessSolute();

    std::vector< Results > Solution;

private:
    std::vector< chessBoard > searchState;
    chessBoard currentComplextion;
};