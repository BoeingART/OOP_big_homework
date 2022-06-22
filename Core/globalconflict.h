#ifndef GLOBALCONFLICT_H
#define GLOBALCONFLICT_H

#include "chessglobal.h"

struct Cor {
    int x;
    int y;
};

class globalConflict {
public:
    bool occ;
    std::string name;

public:
    globalConflict()
        : occ( true )
        , name( "ENPTY" ) {}
    globalConflict( bool occ_, std::string name_ )
        : occ( occ_ )
        , name( name_ ) {}
    void operator=( globalConflict another ) {
        occ = another.occ;
        name = another.name;
    }
};

#endif