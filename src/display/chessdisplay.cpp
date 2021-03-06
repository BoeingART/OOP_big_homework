#include "../../include/display/chessdisplay.h"
#include "../../include/chessmain.h"

#define CC_ 1
#define GY_ 2
#define ZF_ 3
#define ZY_ 4
#define HZ_ 5
#define MC_ 6
#define BA_ 7
#define BB_ 8
#define BC_ 9
#define BD_ 10
#define SP_ 11
#define SQ_ 12
#define HIGH_LIGHT 99

chessDisplay::chessDisplay() {
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    chessGameBoard = newwin( column_number, row_number, size.ws_row / 2 - column_number / 2, size.ws_col / 2 - row_number / 2 );
    chessGameControl = newwin( 0, 0, 0, 0 );
    chessGameHelp = newwin( 2, 10, 1, 1 );
    wrefresh( chessGameBoard );
    wrefresh( chessGameHelp );

    init_pair( CC_, COLOR_RED, COLOR_BLACK );
    init_pair( ZF_, COLOR_BLUE, COLOR_BLACK );
    init_pair( MC_, COLOR_CYAN, COLOR_BLACK );
    init_pair( GY_, COLOR_GREEN, COLOR_BLACK );
    init_pair( ZY_, COLOR_MAGENTA, COLOR_BLACK );
    init_pair( HZ_, COLOR_YELLOW, COLOR_BLACK );
    init_pair( BA_, COLOR_WHITE, COLOR_BLACK );
    init_pair( BB_, COLOR_WHITE, COLOR_BLACK );
    init_pair( BC_, COLOR_WHITE, COLOR_BLACK );
    init_pair( BD_, COLOR_WHITE, COLOR_BLACK );
}

void chessDisplay::displayChess( char name ) {
    int chessChooseNumber[ 12 ];
    for ( int i = 0; i < 12; i++ ) {
        chessChooseNumber[ i ] = -1;
    }

    //对应顺序：曹操、关羽、张飞、赵云、黄忠、马超、兵A、兵B、兵C、兵D、空格1、空格2
    for ( int i = 0; i < chessMain::line(); i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            int k = chooseShowChess( i, j, chessChooseNumber );

            if ( highlight( name, i, j ) )
                wattron( chessGameBoard, A_BOLD );
            wattron( chessGameBoard, COLOR_PAIR( k + 1 ) );

            if ( ( name == 'p' || name == 'q' ) && highlight( name, i, j ) )
                mvwprintw( chessGameBoard, 3 + column_times * j, 6 + row_times * i, "[]" );
            else if ( chessControl::chessCurrentComplextion( i, j ).name == 'c' )
                mvwprintw( chessGameBoard, 5 + column_times * j, 6 + row_times * i, chessMain::chessBoardInfo( i, j, chessChooseNumber[ k ] ) );
            else
                mvwprintw( chessGameBoard, 3 + column_times * j, 6 + row_times * i, chessMain::chessBoardInfo( i, j, chessChooseNumber[ k ] ) );

            if ( highlight( name, i, j ) )
                wattroff( chessGameBoard, A_BOLD );
            wattroff( chessGameBoard, COLOR_PAIR( k + 1 ) );
        }
    }
}

void chessDisplay::displayBoard() {
    init_color( COLOR_WHITE, 1000, 1000, 1000 );
    // edge of board
    mvwprintw( chessGameBoard, 0, 0, "╔" );
    mvwprintw( chessGameBoard, 0, row_number - 1, "╗" );
    mvwprintw( chessGameBoard, column_number - 1, 0, "╚" );
    mvwprintw( chessGameBoard, column_number - 1, row_number - 1, "╝" );

    for ( int i = 1; i < row_number - 1; i++ ) {
        mvwprintw( chessGameBoard, 0, i, "═" );
        mvwprintw( chessGameBoard, column_number - 1, i, "═" );
    }
    for ( int j = 1; j < column_number - 1; j++ ) {
        mvwprintw( chessGameBoard, j, 0, "║" );
        mvwprintw( chessGameBoard, j, row_number - 1, "║" );
    }

    // four corners
    mvwprintw( chessGameBoard, 1, 2, "┏" );
    mvwprintw( chessGameBoard, 1, row_number - 3, "┓" );
    mvwprintw( chessGameBoard, column_number - 2, 2, "┗" );
    mvwprintw( chessGameBoard, column_number - 2, row_number - 3, "┛" );

    // all sides of chess board
    for ( int i = 0; i < chessMain::line(); i++ ) {
        mvwprintw( chessGameBoard, 1, 3 + i * row_times, "━━━━━━━━" );
        mvwprintw( chessGameBoard, column_number - 2, 3 + i * row_times, "━━━━━━━━" );
    }
    for ( int j = 0; j < chessMain::row(); j++ ) {
        for ( int k = 2; k <= 4; k++ ) {
            mvwprintw( chessGameBoard, k + j * column_times, 2, "┃" );
            mvwprintw( chessGameBoard, k + j * column_times, row_number - 3, "┃" );
        }
    }

    // judge the inner lines and print lines

    for ( int i = 0; i < chessMain::line() - 1; i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            if ( sameChess( i, j, i + 1, j ) ) {
                boardLine[ i ][ j ] = false;
            } else {
                for ( int k = 0; k <= 2; k++ ) {
                    mvwprintw( chessGameBoard, ( j + 1 ) * column_times - k, ( i + 1 ) * row_times + 2, "┃" );
                    mvwprintw( chessGameBoard, ( j + 1 ) * column_times - k, ( i + 1 ) * row_times + 2, "┃" );
                }
                boardLine[ i ][ j ] = true;
            }
        }
    }

    for ( int i = 0; i < chessMain::line(); i++ ) {
        for ( int j = 0; j < chessMain::row() - 1; j++ ) {
            if ( sameChess( i, j, i, j + 1 ) ) {
                boardRow[ i ][ j ] = false;
            } else {
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, i * row_times + 3, "━━━━━━━━" );
                boardRow[ i ][ j ] = true;
            }
        }
    }

    // print cross line on edge
    for ( int i = 0; i < chessMain::line() - 1; i++ ) {
        if ( boardLine[ i ][ 0 ] )
            mvwprintw( chessGameBoard, 1, ( i + 1 ) * row_times + 2, "┳" );
        else
            mvwprintw( chessGameBoard, 1, ( i + 1 ) * row_times + 2, "━" );
        if ( boardLine[ i ][ chessMain::row() - 1 ] )
            mvwprintw( chessGameBoard, column_number - 2, ( i + 1 ) * row_times + 2, "┻" );
        else
            mvwprintw( chessGameBoard, column_number - 2, ( i + 1 ) * row_times + 2, "━" );
    }

    for ( int j = 0; j < chessMain::row() - 1; j++ ) {
        if ( boardRow[ 0 ][ j ] )
            mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, 2, "┣" );
        else
            mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, 2, "┃" );
        if ( boardRow[ chessMain::line() - 1 ][ j ] )
            mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, row_number - 3, "┫" );
        else
            mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, row_number - 3, "┃" );
    }

    // print crosses in the chess board
    for ( int i = 0; i < chessMain::line() - 1; i++ ) {
        for ( int j = 0; j < chessMain::row() - 1; j++ ) {
            switch ( crossJudge( i, j ) ) {
            case 0:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "╋" );
                break;
            case 1:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "┳" );
                break;
            case 2:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "┻" );
                break;
            case 3:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "┣" );
                break;
            case 4:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "┫" );
                break;
            case 10:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "━" );
                break;
            case 20:
                mvwprintw( chessGameBoard, ( j + 1 ) * column_times + 1, ( i + 1 ) * row_times + 2, "┃" );
                break;
            default:
                break;
            }
        }
    }
}

void chessDisplay::highlightCurrentChess( char name ) {
    Cor highlightChessCor = getHighlight( name );
    Cor k;
    if ( name == 'c' )
        k = { 1, 1 };
    if ( name == 'g' )
        k = { 1, 0 };
    if ( name == 'f' || name == 'y' || name == 'm' || name == 'h' )
        k = { 0, 1 };
    if ( ( '1' <= name && name <= '4' ) || name == 'p' || name == 'q' )
        k = { 0, 0 };

    mvwprintw( chessGameBoard, 2 + column_times * highlightChessCor.y, 4 + row_times * highlightChessCor.x, "╭" );  //│╭─╮╰╯
    mvwprintw( chessGameBoard, 2 + column_times * highlightChessCor.y, 9 + row_times * ( highlightChessCor.x + k.x ), "╮" );
    mvwprintw( chessGameBoard, 4 + column_times * ( highlightChessCor.y + k.y ), 4 + row_times * highlightChessCor.x, "╰" );
    mvwprintw( chessGameBoard, 4 + column_times * ( highlightChessCor.y + k.y ), 9 + row_times * ( highlightChessCor.x + k.x ), "╯" );

    for ( int i = 1; i <= k.x * row_times + 4; i++ ) {
        mvwprintw( chessGameBoard, 2 + column_times * highlightChessCor.y, i + 4 + row_times * highlightChessCor.x, "─" );
        mvwprintw( chessGameBoard, 4 + column_times * ( highlightChessCor.y + k.y ), i + 4 + row_times * highlightChessCor.x, "─" );
    }
    for ( int j = 1; j <= k.y * column_times + 1; j++ ) {
        mvwprintw( chessGameBoard, j + 2 + column_times * highlightChessCor.y, 4 + row_times * highlightChessCor.x, "│" );
        mvwprintw( chessGameBoard, j + 2 + column_times * highlightChessCor.y, 9 + row_times * ( highlightChessCor.x + k.x ), "│" );
    }
}

void chessDisplay::display( char name ) {
    curs_set( 0 );
    werase( chessGameBoard );
    displayChess( name );
    displayBoard();
    highlightCurrentChess( name );
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

int chessDisplay::chooseShowChess( int x, int y, int ( &chessNumber )[ 12 ] ) {
    switch ( chessControl::chessCurrentComplextion( x, y ).name ) {
    case 'c':
        chessNumber[ 0 ]++;
        return 0;
        break;
    case 'g':
        chessNumber[ 1 ]++;
        return 1;
        break;
    case 'f':
        chessNumber[ 2 ]++;
        return 2;
        break;
    case 'y':
        chessNumber[ 3 ]++;
        return 3;
        break;
    case 'h':
        chessNumber[ 4 ]++;
        return 4;
        break;
    case 'm':
        chessNumber[ 5 ]++;
        return 5;
        break;
    case '1':
        chessNumber[ 6 ]++;
        return 6;
        break;
    case '2':
        chessNumber[ 7 ]++;
        return 7;
        break;
    case '3':
        chessNumber[ 8 ]++;
        return 8;
        break;
    case '4':
        chessNumber[ 9 ]++;
        return 9;
        break;
    case 'p':
        chessNumber[ 10 ]++;
        return 10;
        break;
    case 'q':
        chessNumber[ 11 ]++;
        return 11;
        break;
    default:
        return -1;
    }
}

bool chessDisplay::highlight( char name, int x, int y ) {
    return ( name == chessControl::chessCurrentComplextion( x, y ).name );
}

bool chessDisplay::sameChess( int x1, int y1, int x2, int y2 ) {
    if ( chessControl::chessCurrentComplextion( x1, y1 ).name == 'p' && chessControl::chessCurrentComplextion( x2, y2 ).name == 'q' )
        return true;
    if ( chessControl::chessCurrentComplextion( x1, y1 ).name == 'q' && chessControl::chessCurrentComplextion( x2, y2 ).name == 'p' )
        return true;
    return chessControl::chessCurrentComplextion( x1, y1 ).name == chessControl::chessCurrentComplextion( x2, y2 ).name;
}

int chessDisplay::crossJudge( int x, int y ) {
    if ( boardLine[ x ][ y ] && boardLine[ x ][ y + 1 ] && boardRow[ x ][ y ] && boardRow[ x + 1 ][ y ] )
        return 0;
    if ( !boardLine[ x ][ y ] && boardLine[ x ][ y + 1 ] && boardRow[ x ][ y ] && boardRow[ x + 1 ][ y ] )
        return 1;
    if ( boardLine[ x ][ y ] && !boardLine[ x ][ y + 1 ] && boardRow[ x ][ y ] && boardRow[ x + 1 ][ y ] )
        return 2;
    if ( boardLine[ x ][ y ] && boardLine[ x ][ y + 1 ] && !boardRow[ x ][ y ] && boardRow[ x + 1 ][ y ] )
        return 3;
    if ( boardLine[ x ][ y ] && boardLine[ x ][ y + 1 ] && boardRow[ x ][ y ] && !boardRow[ x + 1 ][ y ] )
        return 4;
    if ( !boardLine[ x ][ y ] && !boardLine[ x ][ y + 1 ] && boardRow[ x ][ y ] && boardRow[ x + 1 ][ y ] )
        return 10;
    if ( boardLine[ x ][ y ] && boardLine[ x ][ y + 1 ] && !boardRow[ x ][ y ] && !boardRow[ x + 1 ][ y ] )
        return 20;
    if ( !boardLine[ x ][ y ] && !boardLine[ x ][ y + 1 ] && !boardRow[ x ][ y ] && !boardRow[ x + 1 ][ y ] )
        return 99;
    return -1;
}

int chessDisplay::gameBoardInput() {
    return wgetch( chessGameBoard );
}

bool GUI_init() {
    setlocale( LC_ALL, "" );  //同步终端字符库
    initscr();                // 初始化并进入curses 模式
    if ( has_colors() == false )
        return false;
    noecho();
    start_color();
    cbreak();  // 行缓冲禁止，传递所有控制信息
    return true;
}

Cor chessDisplay::getHighlight( char name ) {
    for ( int i = 0; i < chessMain::line(); i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            if ( highlight( name, i, j ) ) {
                return { i, j };
            }
        }
    }
    return { 0, 0 };
}
