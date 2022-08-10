#include "../../include/display/chessboardwindow.h"
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

chessBoardWindow::chessBoardWindow() {
    struct winsize size;
    ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
    gameBoardWindow = newwin( board_col_number, board_row_number, size.ws_row / 2 - board_col_number / 2, ( size.ws_col + side_col_number ) / 2 - board_row_number / 2 );
    gameSideWindow = newwin( side_col_number, side_row_number, size.ws_row / 2 - side_col_number / 2, ( size.ws_col - side_col_number ) / 2 - board_row_number / 2 );
    gameWinWindow = newwin( 30, 6, size.ws_row / 2 - 15, size.ws_col / 2 - 3 );

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

    keypad( gameBoardWindow, true );
}

void chessBoardWindow::displayChess( char name ) {
    int chessChooseNumber[ 12 ];
    for ( int i = 0; i < 12; i++ ) {
        chessChooseNumber[ i ] = -1;
    }

    //对应顺序：曹操、关羽、张飞、赵云、黄忠、马超、兵A、兵B、兵C、兵D、空格1、空格2
    for ( int i = 0; i < chessMain::col(); i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            int k = chooseShowChess( i, j, chessChooseNumber );

            if ( highlight( name, i, j ) )
                wattron( gameBoardWindow, A_BOLD );
            wattron( gameBoardWindow, COLOR_PAIR( k + 1 ) );

            if ( ( name == 'p' || name == 'q' ) && highlight( name, i, j ) )
                mvwprintw( gameBoardWindow, 3 + col_times * j, 6 + row_times * i, "[]" );
            else if ( chessControl::chessCurrentComplextion( i, j ).name == 'c' )
                mvwprintw( gameBoardWindow, 5 + col_times * j, 6 + row_times * i, chessMain::chessBoardInfo( i, j, chessChooseNumber[ k ] ) );
            else
                mvwprintw( gameBoardWindow, 3 + col_times * j, 6 + row_times * i, chessMain::chessBoardInfo( i, j, chessChooseNumber[ k ] ) );

            if ( highlight( name, i, j ) )
                wattroff( gameBoardWindow, A_BOLD );
            wattroff( gameBoardWindow, COLOR_PAIR( k + 1 ) );
        }
    }
}

void chessBoardWindow::displayBoard() {
    // edge of board
    mvwprintw( gameBoardWindow, 0, 0, "╔" );
    mvwprintw( gameBoardWindow, 0, board_row_number - 1, "╗" );
    mvwprintw( gameBoardWindow, board_col_number - 1, 0, "╚" );
    mvwprintw( gameBoardWindow, board_col_number - 1, board_row_number - 1, "╝" );

    for ( int i = 1; i < board_row_number - 1; i++ ) {
        mvwprintw( gameBoardWindow, 0, i, "═" );
        mvwprintw( gameBoardWindow, board_col_number - 1, i, "═" );
    }
    for ( int j = 1; j < board_col_number - 1; j++ ) {
        mvwprintw( gameBoardWindow, j, 0, "║" );
        mvwprintw( gameBoardWindow, j, board_row_number - 1, "║" );
    }

    // four corners
    mvwprintw( gameBoardWindow, 1, 2, "┏" );
    mvwprintw( gameBoardWindow, 1, board_row_number - 3, "┓" );
    mvwprintw( gameBoardWindow, board_col_number - 2, 2, "┗" );
    mvwprintw( gameBoardWindow, board_col_number - 2, board_row_number - 3, "┛" );

    // all sides of chess board
    for ( int i = 0; i < chessMain::col(); i++ ) {
        mvwprintw( gameBoardWindow, 1, 3 + i * row_times, "━━━━━━━━" );
        mvwprintw( gameBoardWindow, board_col_number - 2, 3 + i * row_times, "━━━━━━━━" );
    }
    for ( int j = 0; j < chessMain::row(); j++ ) {
        for ( int k = 2; k <= 4; k++ ) {
            mvwprintw( gameBoardWindow, k + j * col_times, 2, "┃" );
            mvwprintw( gameBoardWindow, k + j * col_times, board_row_number - 3, "┃" );
        }
    }

    // judge the inner lines and print lines

    for ( int i = 0; i < chessMain::col() - 1; i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            if ( sameChess( i, j, i + 1, j ) ) {
                boardLine[ i ][ j ] = false;
            } else {
                for ( int k = 0; k <= 2; k++ ) {
                    mvwprintw( gameBoardWindow, ( j + 1 ) * col_times - k, ( i + 1 ) * row_times + 2, "┃" );
                    mvwprintw( gameBoardWindow, ( j + 1 ) * col_times - k, ( i + 1 ) * row_times + 2, "┃" );
                }
                boardLine[ i ][ j ] = true;
            }
        }
    }

    for ( int i = 0; i < chessMain::col(); i++ ) {
        for ( int j = 0; j < chessMain::row() - 1; j++ ) {
            if ( sameChess( i, j, i, j + 1 ) ) {
                boardRow[ i ][ j ] = false;
            } else {
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, i * row_times + 3, "━━━━━━━━" );
                boardRow[ i ][ j ] = true;
            }
        }
    }

    // print cross line on edge
    for ( int i = 0; i < chessMain::col() - 1; i++ ) {
        if ( boardLine[ i ][ 0 ] )
            mvwprintw( gameBoardWindow, 1, ( i + 1 ) * row_times + 2, "┳" );
        else
            mvwprintw( gameBoardWindow, 1, ( i + 1 ) * row_times + 2, "━" );
        if ( boardLine[ i ][ chessMain::row() - 1 ] )
            mvwprintw( gameBoardWindow, board_col_number - 2, ( i + 1 ) * row_times + 2, "┻" );
        else
            mvwprintw( gameBoardWindow, board_col_number - 2, ( i + 1 ) * row_times + 2, "━" );
    }

    for ( int j = 0; j < chessMain::row() - 1; j++ ) {
        if ( boardRow[ 0 ][ j ] )
            mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, 2, "┣" );
        else
            mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, 2, "┃" );
        if ( boardRow[ chessMain::col() - 1 ][ j ] )
            mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, board_row_number - 3, "┫" );
        else
            mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, board_row_number - 3, "┃" );
    }

    // print crosses in the chess board
    for ( int i = 0; i < chessMain::col() - 1; i++ ) {
        for ( int j = 0; j < chessMain::row() - 1; j++ ) {
            switch ( crossJudge( i, j ) ) {
            case 0:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "╋" );
                break;
            case 1:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "┳" );
                break;
            case 2:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "┻" );
                break;
            case 3:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "┣" );
                break;
            case 4:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "┫" );
                break;
            case 10:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "━" );
                break;
            case 20:
                mvwprintw( gameBoardWindow, ( j + 1 ) * col_times + 1, ( i + 1 ) * row_times + 2, "┃" );
                break;
            default:
                break;
            }
        }
    }
}

void chessBoardWindow::displaySide() {
    box( gameSideWindow, 0, 0 );
}

void chessBoardWindow::highlightCurrentChess( char name ) {
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

    mvwprintw( gameBoardWindow, 2 + col_times * highlightChessCor.y, 4 + row_times * highlightChessCor.x, "╭" );  //│╭─╮╰╯
    mvwprintw( gameBoardWindow, 2 + col_times * highlightChessCor.y, 9 + row_times * ( highlightChessCor.x + k.x ), "╮" );
    mvwprintw( gameBoardWindow, 4 + col_times * ( highlightChessCor.y + k.y ), 4 + row_times * highlightChessCor.x, "╰" );
    mvwprintw( gameBoardWindow, 4 + col_times * ( highlightChessCor.y + k.y ), 9 + row_times * ( highlightChessCor.x + k.x ), "╯" );

    for ( int i = 1; i <= k.x * row_times + 4; i++ ) {
        mvwprintw( gameBoardWindow, 2 + col_times * highlightChessCor.y, i + 4 + row_times * highlightChessCor.x, "─" );
        mvwprintw( gameBoardWindow, 4 + col_times * ( highlightChessCor.y + k.y ), i + 4 + row_times * highlightChessCor.x, "─" );
    }
    for ( int j = 1; j <= k.y * col_times + 1; j++ ) {
        mvwprintw( gameBoardWindow, j + 2 + col_times * highlightChessCor.y, 4 + row_times * highlightChessCor.x, "│" );
        mvwprintw( gameBoardWindow, j + 2 + col_times * highlightChessCor.y, 9 + row_times * ( highlightChessCor.x + k.x ), "│" );
    }
}

void chessBoardWindow::display( char name ) {
    werase( gameBoardWindow );
    werase( gameSideWindow );
    displayChess( name );
    displayBoard();
    displaySide();
    highlightCurrentChess( name );
    wrefresh( gameBoardWindow );
    wrefresh( gameSideWindow );
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

int chessBoardWindow::chooseShowChess( int x, int y, int ( &chessNumber )[ 12 ] ) {
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

bool chessBoardWindow::highlight( char name, int x, int y ) {
    return ( name == chessControl::chessCurrentComplextion( x, y ).name );
}

bool chessBoardWindow::sameChess( int x1, int y1, int x2, int y2 ) {
    if ( chessControl::chessCurrentComplextion( x1, y1 ).name == 'p' && chessControl::chessCurrentComplextion( x2, y2 ).name == 'q' )
        return true;
    if ( chessControl::chessCurrentComplextion( x1, y1 ).name == 'q' && chessControl::chessCurrentComplextion( x2, y2 ).name == 'p' )
        return true;
    return chessControl::chessCurrentComplextion( x1, y1 ).name == chessControl::chessCurrentComplextion( x2, y2 ).name;
}

int chessBoardWindow::crossJudge( int x, int y ) {
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

int chessBoardWindow::gameBoardInput() {
    return wgetch( gameBoardWindow );
}

bool GUI_init() {
    setlocale( LC_ALL, "" );  //同步终端字符库
    initscr();                // 初始化并进入curses 模式
    if ( has_colors() == false )
        return false;
    noecho();
    start_color();
    keypad( stdscr, true );  //允许使用特殊功能键
    cbreak();                // 行缓冲禁止，传递所有控制信息
    curs_set( 0 );
    return true;
}

Cor chessBoardWindow::getHighlight( char name ) {
    for ( int i = 0; i < chessMain::col(); i++ ) {
        for ( int j = 0; j < chessMain::row(); j++ ) {
            if ( highlight( name, i, j ) ) {
                return { i, j };
            }
        }
    }
    return { 0, 0 };
}

void chessBoardWindow::clean() {
    wclear( gameBoardWindow );
    wclear( gameSideWindow );
    wclear( gameWinWindow );

    wrefresh( gameBoardWindow );
    wrefresh( gameSideWindow );
    wrefresh( gameWinWindow );
}
