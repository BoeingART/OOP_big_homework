#ifndef GLOBALCONFLICT_H
#define GLOBALCONFLICT_H

#include "chessglobal.h"

struct Cor {
    int x;
    int y;
    void operator=( const Cor& another ) {
        x = another.x;
        y = another.y;
    }
    void operator+=( const Cor& another ) {
        x += another.x;
        y += another.y;
    }
};

struct UR_operation {
    char chessName;
    char direction;
    UR_operation( char name, char dir )
        : chessName( name )
        , direction( dir ) {}
};

class globalConflict {
public:
    bool occ;
    char name;

public:
    globalConflict()
        : occ( true )
        , name( '\0' ) {}
    globalConflict( bool occ_, char name_ )
        : occ( occ_ )
        , name( name_ ) {}
    void operator=( globalConflict another ) {
        occ = another.occ;
        name = another.name;
    }
};

#endif