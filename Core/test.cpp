#include <cstring>
#include <ncurses.h>

void print_in_middle( WINDOW* win, int starty, int startx, int width, char* string );
int main( int argc, char* argv[] ) {
    initscr(); /*启动curses 模式*/
    if ( has_colors() == FALSE ) {
        endwin();
        printf( "You terminal does not support color/n" );
        return 0;
    }
    start_color(); /*启动color 机制*/
    WINDOW* test = newwin( 10, 30, 10, 0 );
    box( test, 0, 0 );
    init_pair( 1, COLOR_RED, COLOR_WHITE );
    wattron( test, COLOR_PAIR( 1 ) );
    wprintw( test, "Viola !!! In color ..." );
    //print_in_middle( stdscr, LINES / 2, 0, 0, "Viola !!! In color ..." );
    wattroff( test, COLOR_PAIR( 1 ) );
    wrefresh( test );
    wgetch( test );
    endwin();
}
void print_in_middle( WINDOW* win, int starty, int startx, int width, char* string ) {
    int length, x, y;
    float temp;
    if ( win == NULL )
        win = stdscr;
    getyx( win, y, x );
    if ( startx != 0 )
        x = startx;
    if ( starty != 0 )
        y = starty;
    if ( width == 0 )
        width = 80;
    length = strlen( string );
    temp = ( width ) / 2;
    x = startx + ( int )temp;
    mvwprintw( win, y, x, "%s", string );
    refresh();
}