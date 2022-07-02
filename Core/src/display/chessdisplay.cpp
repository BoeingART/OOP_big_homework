#include "../../include/display/chessdisplay.h"

chessDisplay::chessDisplay(){
    
}

void chessDisplay::space_print( int number ) {
    for ( int i = 0; i < number; i++ ) {
        printf( " " );
    }
}

void chessDisplay::enter_print( int number ) {
    for ( int i = 0; i < number; i++ ) {
        printf( "\n" );
    }
}

void chessDisplay::display( char name ) {
    /*
    
    system( "clear" );
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    int up_down_space = ( size.ws_row - 11 ) / 2;
    int left_right_space = ( size.ws_col - 21 ) / 2;
    enter_print( up_down_space );
    space_print( left_right_space );
    printf( "┏━━━━┳━━━━┳━━━━┳━━━━┓" );
    printf( "\n" );
    int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0;
    for ( int i = 0; i < chessMain::row(); i++ ) {
        space_print( left_right_space - 23 );
        if ( i == 0 )
            printf( "↑ ↓ ← →     选择棋子   " );
        else if ( i == 1 )
            printf( "W A S D     移动棋子   " );
        else if ( i == 2 )
            printf( "N + (0~4)   重置棋盘   " );
        else if ( i == 3 )
            printf( "  U/R       撤销/恢复  " );
        else if ( i == 4 )
            printf( "   Q        退出       " );
        printf( "┃" );
        for ( int j = 0; j < chessMain::line(); j++ ) {
            if ( chessMain::chessBoardInfo( j, i ).occ ) {
                if ( chessMain::chessBoardInfo( j, i ).name == 'c' ) {
                    if ( name == 'c' )
                        printf( "\033[1;31m" );
                    else
                        printf( "\033[31m" );
                    switch ( CC ) {
                    case 0:
                        printf( " 曹 " );
                        break;
                    case 1:
                        printf( " 曹 " );
                        break;
                    case 2:
                        printf( " 操 " );
                        break;
                    case 3:
                        printf( " 操 " );
                        break;
                    default:
                        break;
                    }
                    printf( "\033[0m" );
                    CC++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'f' ) {
                    if ( name == 'f' )
                        printf( "\033[1;32m" );
                    else
                        printf( "\033[32m" );
                    switch ( ZF ) {
                    case 0:
                        printf( " 张 " );
                        break;
                    case 1:
                        printf( " 飞 " );
                        break;
                    }
                    printf( "\033[0m" );
                    ZF++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'm' ) {
                    if ( name == 'm' )
                        printf( "\033[1;33m" );
                    else
                        printf( "\033[33m" );
                    switch ( MC ) {
                    case 0:
                        printf( " 马 " );
                        break;
                    case 1:
                        printf( " 超 " );
                        break;
                    }
                    printf( "\033[0m" );
                    MC++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'g' ) {
                    if ( name == 'g' )
                        printf( "\033[1;34m" );
                    else
                        printf( "\033[34m" );
                    switch ( GY ) {
                    case 0:
                        printf( " 关 " );
                        break;
                    case 1:
                        printf( " 羽 " );
                        break;
                    }
                    printf( "\033[0m" );
                    GY++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'h' ) {
                    if ( name == 'h' )
                        printf( "\033[1;35m" );
                    else
                        printf( "\033[35m" );
                    switch ( HZ ) {
                    case 0:
                        printf( " 黄 " );
                        break;
                    case 1:
                        printf( " 忠 " );
                        break;
                    }
                    printf( "\033[0m" );
                    HZ++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'y' ) {
                    if ( name == 'y' )
                        printf( "\033[1;36m" );
                    else
                        printf( "\033[36m" );
                    switch ( ZY ) {
                    case 0:
                        printf( " 赵 " );
                        break;
                    case 1:
                        printf( " 云 " );
                        break;
                    }
                    printf( "\033[0m" );
                    ZY++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == '1' ) {
                    if ( name == '1' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                } else if ( chessMain::chessBoardInfo( j, i ).name == '2' ) {
                    if ( name == '2' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                } else if ( chessMain::chessBoardInfo( j, i ).name == '3' ) {
                    if ( name == '3' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                } else if ( chessMain::chessBoardInfo( j, i ).name == '4' ) {
                    if ( name == '4' )
                        printf( "\033[1;37m" );
                    else
                        printf( "\033[37m" );
                    printf( " 兵 " );
                    printf( "\033[0m" );
                }
            } else {
                if ( chessMain::chessBoardInfo( j, i ).name == 'p' ) {
                    if ( name == 'p' )
                        printf( "\033[1;47m [] \033[0m" );
                    else
                        printf( "\033[1;30m    \033[0m" );
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'q' ) {
                    if ( name == 'q' )
                        printf( "\033[1;47m [] \033[0m" );
                    else
                        printf( "\033[1;30m    \033[0m" );
                }
            }
            printf( "┃" );
        }
        printf( "\n" );
        if ( i != chessMain::row() - 1 ) {
            space_print( left_right_space );
            printf( "┣━━━━╋━━━━╋━━━━╋━━━━┫\n" );
        } else {
            space_print( left_right_space );
            printf( "┗━━━━┻━━━━┻━━━━┻━━━━┛\n" );
        }
    }
    */
}

bool windowDetect() {
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    printf( "%s%d%s%d\n", "当前窗口大小为：", size.ws_col, " × ", size.ws_row );
    if ( size.ws_row < 16 )
        return false;
    else if ( size.ws_col < 70 )
        return false;
    else
        return true;
}