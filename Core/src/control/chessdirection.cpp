#include "../../include/control/chessdirection.h"

bool chessDirection::operator==( const chessDirection& _direction ) {
    if ( dir.x == _direction.dir.x && dir.y == _direction.dir.y )
        return true;
    else
        return false;
}

void chessDirection::operator=( const chessDirection& _direction ) {
    this->dir = _direction.dir;
}