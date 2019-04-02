//
// Created by kondiiq on 05.03.19.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include <iostream>
#include <string>
#include <cmath>
#include "MSBoardTextView.h"
#include <ctime>

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum game_mode { debug , easy , medium , hard};
enum game_state {running , finish_win , finish_loss};

class MinesweeperBoard
{
    Field board[100][100];
    int boardwidth;
    int boardheight;
    int player_action;
    game_mode mode;
    game_state status;
    void fill_board();
    void set_field(int row, int col , bool hasMine , bool hasFlag , bool isRevealed);



public:

    MinesweeperBoard();
    MinesweeperBoard( int height , int width , game_mode stan);
    void debug_display();
    void mine_generator();
    int mine_counter(int row , int column) const;
    bool hasFlag(int row , int column) const ;
    void toggleFlag(int row , int column);
    void revealField( int row , int column);
    bool isRevealed(int row, int column) const;
    game_state getGameState()const ;
    char getFieldInfo(int x, int y) const;
//    int getBoardWidth() const;
//    int getBoardHeight() const;
//    int getMineCount() const ;




};


#endif //SAPER_MINESWEEPERBOARD_H
