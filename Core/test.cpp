#include "stdio.h"

int main() {
    char sText[ 30 ] = "多字节字符串！OK！";
    for ( int i = 0; i < 30; i = i + 3 ) {
        printf( "%c%c%c", sText[ i ], sText[ i + 1 ], sText[ i + 2 ] );
        printf( "%d\n", i );
    }
    return 0;
}