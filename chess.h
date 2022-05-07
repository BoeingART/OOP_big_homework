#ifndef CHESS_H
#define CHESS_H

#include "global.h"

class chess: public QPushButton
{
public:
    chess(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    const int stepDistance = 5;


};

#endif // CHESS_H
