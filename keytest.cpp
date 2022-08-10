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
    WINDOW* test1 = newwin( 10, 10, 10, 10 );
    WINDOW* test2 = newwin( 10, 10, 11, 11 );
    box( test1, 0, 0 );
    box( test2, 0, 0 );
    wrefresh( test1 );
    wrefresh( test2 );
    getch();
    curs_set( 1 );
    endwin();
    return 0;
}