#include "../../include/display/chessdisplay.h"
#include "../../include/chessmain.h"

chessDisplay::chessDisplay() {
    chessGameBoard = newwin( 11, 22, 4, 4 );
    chessGameControl = newwin( 0, 0, 0, 0 );
    chessGameHelp = newwin( 2, 10, 1, 1 );
    box( chessGameBoard, 0, 0 );
    // box( chessGameControl, 0, 0 );
    box( chessGameHelp, 0, 0 );
    wrefresh( chessGameBoard );
    // wrefresh( chessGameControl );
    wrefresh( chessGameHelp );
}

void chessDisplay::display( char name ) {
    werase( chessGameBoard );
    wprintw( chessGameBoard, "┏━━━━┳━━━━┳━━━━┳━━━━┓\n" );
    int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0;
    init_pair( 1, COLOR_RED, COLOR_WHITE );
    for ( int i = 0; i < chessMain::row(); i++ ) {
        wprintw( chessGameBoard, "┃" );
        for ( int j = 0; j < chessMain::line(); j++ ) {
            if ( chessMain::chessBoardInfo( j, i ).occ ) {
                if ( chessMain::chessBoardInfo( j, i ).name == 'c' ) {
                    if ( name == 'c' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    switch ( CC ) {
                    case 0:
                        wprintw( chessGameBoard, " 曹 " );
                        break;
                    case 1:
                        wprintw( chessGameBoard, " 曹 " );
                        break;
                    case 2:
                        wprintw( chessGameBoard, " 操 " );
                        break;
                    case 3:
                        wprintw( chessGameBoard, " 操 " );
                        break;
                    default:
                        break;
                    }
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                    CC++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'f' ) {
                    if ( name == 'f' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    switch ( ZF ) {
                    case 0:
                        wprintw( chessGameBoard, " 张 " );
                        break;
                    case 1:
                        wprintw( chessGameBoard, " 飞 " );
                        break;
                    }
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                    ZF++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'm' ) {
                    if ( name == 'm' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    switch ( MC ) {
                    case 0:
                        wprintw( chessGameBoard, " 马 " );
                        break;
                    case 1:
                        wprintw( chessGameBoard, " 超 " );
                        break;
                    }
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                    MC++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'g' ) {
                    if ( name == 'g' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    switch ( GY ) {
                    case 0:
                        wprintw( chessGameBoard, " 关 " );
                        break;
                    case 1:
                        wprintw( chessGameBoard, " 羽 " );
                        break;
                    }
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                    GY++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'h' ) {
                    if ( name == 'h' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    switch ( HZ ) {
                    case 0:
                        wprintw( chessGameBoard, " 黄 " );
                        break;
                    case 1:
                        wprintw( chessGameBoard, " 忠 " );
                        break;
                    }
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                    HZ++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'y' ) {
                    if ( name == 'y' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    switch ( ZY ) {
                    case 0:
                        wprintw( chessGameBoard, " 赵 " );
                        break;
                    case 1:
                        wprintw( chessGameBoard, " 云 " );
                        break;
                    }
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                    ZY++;
                } else if ( chessMain::chessBoardInfo( j, i ).name == '1' ) {
                    if ( name == '1' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    wprintw( chessGameBoard, " 兵 " );
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                } else if ( chessMain::chessBoardInfo( j, i ).name == '2' ) {
                    if ( name == '2' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    wprintw( chessGameBoard, " 兵 " );
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                } else if ( chessMain::chessBoardInfo( j, i ).name == '3' ) {
                    if ( name == '3' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    wprintw( chessGameBoard, " 兵 " );
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                } else if ( chessMain::chessBoardInfo( j, i ).name == '4' ) {
                    if ( name == '4' )
                        wattron( chessGameBoard, COLOR_PAIR( 1 ) );
                    wprintw( chessGameBoard, " 兵 " );
                    wattroff( chessGameBoard, COLOR_PAIR( 1 ) );
                }
            } else {
                if ( chessMain::chessBoardInfo( j, i ).name == 'p' ) {
                    if ( name == 'p' )
                        wprintw( chessGameBoard, " [] " );
                    else
                        wprintw( chessGameBoard, "    " );
                } else if ( chessMain::chessBoardInfo( j, i ).name == 'q' ) {
                    if ( name == 'q' )
                        wprintw( chessGameBoard, " [] " );
                    else
                        wprintw( chessGameBoard, "    " );
                }
            }
            wprintw( chessGameBoard, "┃" );
        }
        wprintw( chessGameBoard, "\n" );
        if ( i != chessMain::row() - 1 ) {
            wprintw( chessGameBoard, "┣━━━━╋━━━━╋━━━━╋━━━━┫\n" );
        } else {
            wprintw( chessGameBoard, "┗━━━━┻━━━━┻━━━━┻━━━━┛\n" );
        }
    }

    wrefresh( chessGameBoard );
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