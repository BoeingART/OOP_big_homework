#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "global.h"
#include "chess.h"

class gameWindow: public QMainWindow
{

public:
    gameWindow(QWidget *parent = nullptr);
    //void keyPressEvent(QKeyEvent *event);
private:
    const int window_width = 450;
    const int window_height = 800;
    const QSize window = {window_width, window_height};
    QWidget *chessBoard;
    void setChessBoard();
    void setChess();
};

#endif // GAMEWINDOW_H
