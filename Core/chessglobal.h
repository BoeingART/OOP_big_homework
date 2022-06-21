#ifndef CHESSGLOBAL_H
#define CHESSGLOBAL_H

#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

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
        , name( "aa" ) {}
    globalConflict( bool occ_, std::string name_ )
        : occ( occ_ )
        , name( name_ ) {}
    void operator=( globalConflict another ) {
        occ = another.occ;
        name = another.name;
    }
    friend std::ostream& operator<<( std::ostream& out, const globalConflict& other ) {
        return out << other.name;
    }
};

#endif
