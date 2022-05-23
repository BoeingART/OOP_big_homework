#ifndef CHESSMAIN_H
#define CHESSMAIN_H

#include "global.h"

#include "chesscontrol.h"
#include "chesscontrolsize1.h"
#include "chesscontrolsize2.h"
#include "chesscontrolsize4.h"
#include "chessmoverecorder.h"
#include "chessdirection.h"
#include <stdio.h>

void inputChessInfo(std::string name, char direction, bool if_undo);
void dirChange(char &Dir);
void chessReset();
#endif