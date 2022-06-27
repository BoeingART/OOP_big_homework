# 华容道

本游戏基于经典中国传统游戏华容道规则设计，可运行在Windows平台和Mac平台下

## 游戏规则

### 游戏目标

将曹操移动至最下方的中央位置游戏即胜利

### 操作方式

用鼠标选中移动棋子

用W、A、S、D操纵棋子移动的方向

在“开始游戏”菜单下选择要游玩的棋局

点击“撤销”可以撤销上一步移动

点击“取消撤销”可以取消撤销

## 代码结构

+  `chessglobal.h`：包括了所有使用的库文件
+ `globalconflict.h`：定义代码中的一些结构体和类
  + `Cor`：棋子的坐标
  + `UR_operation`：向显示界面返回操作顺序
  + `globalConflict`：某处棋子的名称和占据情况
+ `originchessboard.h`：包含各种棋盘的初始局面和当前棋盘的初始局面
+ `chessdirection.h`：定义棋子的移动方向
+ `chesscontrol.h`：
  + 包含棋盘的基本局面、棋子移动和棋子控制等操作方式
  + 有以下子类：
    + `chesscontrolsize1.h`：大小为1单位的棋子
    + `chesscontrolsize2.h`：大小为2单位的棋子
    + `chesscontrolsize4.h`：大小为4单位的棋子
+ `chessmoverecoder.h`：
  + `steps`：记录某步移动棋子名称和方向
  + `chessMoveRecoder`：记录棋子移动并执行*撤销*和*重做*操作

+ `chessmain.h`：封装棋子控制的方法和棋子





## 程序分工

+ 谭臻至：负责华容道游戏的内核实现
+ 栗嘉伟：负责华容道游戏的Qt GUI界面实现