#ifndef CHESSBEGINWINDOW
#define CHESSBEGINWINDOW

#include "../chessglobal.h"

class chessBeginWindow {
public:
    chessBeginWindow();
    void display( int input );
    int Selector();
    void helpDisplay();
    void settingDisplay();
    void clean();

private:
    void beginDisplay();
    void selectDisplay( int input );
    void moveSelector( int input );
    int selector = 0;
    const int column_number = 57;
    const int row_number = 20;

    const int se_col_number = 30;
    const int se_row_number = 10;

    WINDOW* beginWindow;
    WINDOW* selectWindow;

    const char* gameTitle = "\
  ██╗  ██╗██╗      ██████╗ ████████╗███████╗██╗  ██╗██╗\n\
  ██║ ██╔╝██║     ██╔═══██╗╚══██╔══╝██╔════╝██║ ██╔╝██║\n\
  █████╔╝ ██║     ██║   ██║   ██║   ███████╗█████╔╝ ██║\n\
  ██╔═██╗ ██║     ██║   ██║   ██║   ╚════██║██╔═██╗ ██║\n\
  ██║  ██╗███████╗╚██████╔╝   ██║   ███████║██║  ██╗██║\n\
  ╚═╝  ╚═╝╚══════╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝\n";
    const char* gameSelections[ 4 ] = { "开始游戏", "游戏设置", "游戏帮助", "退出游戏" };
};

#endif

//  Klotski
// ┃
// ┃
// ┃╱
// ┃╲