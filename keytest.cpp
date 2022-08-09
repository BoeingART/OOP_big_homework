#include <ctime>
#include <iostream>
#include <ncurses.h>
#include <random>
#include <string>

int main() {
    setlocale( LC_ALL, "" );  //同步终端字符库
    initscr();                // 初始化并进入curses 模式
    noecho();
    start_color();
    cbreak();  // 行缓冲禁止，传递所有控制信息
    curs_set( 0 );
    WINDOW* output = newwin( 0, 0, 20, 10 );
    while ( true ) {
        int input = wgetch( output );
        wclear( output );
        if ( input == 'q' )
            break;
        std::string temp = std::to_string( input );
        const char* result = temp.c_str();
        wprintw( output, result );
    }
    curs_set( 1 );
    endwin();
    return 0;
}