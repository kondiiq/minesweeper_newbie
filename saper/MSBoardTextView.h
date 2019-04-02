//
// Created by kondiiq on 25.03.19.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>


class MSBoardTextView
{
private:
     const MinesweeperBoard *obj_gameboard;

public:
    MSBoardTextView()= default;
    explicit MSBoardTextView(const MinesweeperBoard &gameboard);
    void display();
};

#endif //SAPER_MSBOARDTEXTVIEW_H

