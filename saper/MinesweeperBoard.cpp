//
// Created by Mła on 05.03.19.
//

#include "MinesweeperBoard.h"
#include <iostream>
#include <ctime>

MinesweeperBoard::MinesweeperBoard()
    {
        boardheight = 10;
        boardwidth = 10;
        fill_board();
        player_action = 0;
        status;
        mode = debug;
        getGameState();
        //  debug_display();
        mine_generator();

    }


    MinesweeperBoard::MinesweeperBoard(int height, int width, game_mode stan)
    {
        boardwidth = width;
        boardheight = height;
        mode = stan;
        status;
        player_action = 0;
        fill_board();
        getGameState();
        mine_generator();

        //debug_display();
    }


    void MinesweeperBoard::set_field(int row, int col, bool hasMine, bool hasFlag, bool isRevealed) {
        board[row][col].hasMine = hasMine;
        board[row][col].hasFlag = hasFlag;
        board[row][col].isRevealed = isRevealed;
    }

    void MinesweeperBoard::fill_board() {
        for (int ix = 0; ix < boardwidth; ++ix) {
            for (int iy = 0; iy < boardheight; ++iy) {
                set_field(ix, iy, false, false, false);
            }
        }
    }

    void MinesweeperBoard::mine_generator() {
        int ile_pol, row, column;

        ile_pol = boardheight * boardwidth;

        if (mode == easy) {
            for (int i = 0; i < ile_pol * 0.1; ++i) {
                row = (std::rand() % boardwidth);
                column = (std::rand() % boardheight);

                while (board[row][column].hasMine) {
                    row = (std::rand() % boardwidth);
                    column = (std::rand() % boardheight);
                }
                if (board[row][column].hasMine == false) {
                    board[row][column].hasMine = true;
                }
            }

        } else if (mode == medium) {
            for (int i = 0; i < ile_pol * 0.2; ++i) {
                row = (std::rand() % boardwidth);
                column = (std::rand() % boardheight);

                while (board[row][column].hasMine) {
                    row = (std::rand() % boardwidth);
                    column = (std::rand() % boardheight);
                }
                if (board[row][column].hasMine == false) {
                    board[row][column].hasMine = true;
                }
            }

        } else if (mode == hard) {
            for (int i = 0; i < ile_pol * 0.3; ++i) {
                row = (std::rand() % boardwidth);
                column = (std::rand() % boardheight);

                while (board[row][column].hasMine) {
                    row = (std::rand() % boardwidth);
                    column = (std::rand() % boardheight);
                }
                if (board[row][column].hasMine == false) {
                    board[row][column].hasMine = true;
                }
            }

        } else if (mode == debug) {
            for (int row = 0; row < boardheight; ++row) {
                for (int column = 0; column < boardwidth; ++column) {
                    if (row == column) {
                        set_field(row, column, true, false, false);

                    }

                    if (row == 0) {
                        set_field(row, column, true, false, false);
                    }

                    if (column == 0 and row % 2 == 0) {
                        set_field(row, column, true, false, false);
                    }
                }
            }
        }
    }


    void MinesweeperBoard::debug_display() {
        for (int row = 0; row < boardheight; ++row) {
            for (int column = 0; column < boardwidth; ++column) {
                if (board[row][column].hasFlag)
                    std::cout << "[..f]";
                else if (board[row][column].isRevealed)
                    std::cout << "[.o.]";
                else if (board[row][column].hasMine)
                    std::cout << "[M..]";
                else
                    std::cout << "[...]";
            }
            std::cout << std::endl;
        }
    }

    int MinesweeperBoard::mine_counter(int row, int columna) const // (-1) = field is outside board
    {
        int counter = 0;

        if (row > boardwidth or row < 0 or columna < 0 or columna > boardheight) {
            return -1;
        }


        if (board[row - 1][columna].hasMine == true) {
            if (row == 0) {}
            else
                ++counter;
        }

        if (board[row + 1][columna].hasMine == true) {
            if (row == 9) {}
            else
                ++counter;
        }

        if (board[row][columna - 1].hasMine == true) {
            if (columna == 0) {}
            else
                ++counter;
        }

        if (board[row][columna + 1].hasMine == true) {
            if (columna == 9) {}
            else
                ++counter;
        }

        if (board[row - 1][columna - 1].hasMine == true) {
            if (columna == 0 or row == 0) {}
            else
                ++counter;
        }

        if (board[row + 1][columna + 1].hasMine == true) {
            if (columna == 9 or row == 9) {}
            else
                ++counter;
        }

        if (board[row + 1][columna - 1].hasMine == true) {
            if (columna == 0 or row == 9) {}
            else
                ++counter;
        }

        if (board[row - 1][columna + 1].hasMine == true) {
            if (columna == 9 or row == 0) {}
            else
                ++counter;
        }

        std::cout << std::endl;
        return counter;

    }


    bool MinesweeperBoard::hasFlag(int x, int y) const {

        if (x < 0 or y < 0 or x > boardwidth or y > boardheight) {
            std::cout << " You are outboard " << std::endl;
            return false;
        }

        if (!board[x][y].hasFlag == false) {
            return false;
        }

        if (board[x][y].isRevealed == true) {
            return false;
        }

        if (board[x][y].hasFlag == true) {
            return true;
        }
    }

    void MinesweeperBoard::toggleFlag(int x, int y)
    {

        if (board[x][y].isRevealed == true) {}

        if (x < 0 or y < 0 or x > boardwidth or y > boardheight) {}

        if (status == finish_win or status == finish_loss) {}

        if (board[x][y].isRevealed == false)
        {
            board[x][y].hasFlag = true;
        }
    }

    void MinesweeperBoard::revealField(int x, int y) {
        if (x < 0 or y < 0 or x > boardwidth or y > boardheight) {}

        if (board[x][y].isRevealed == true) {}

        if (status == finish_loss or status == finish_win) {}

        if (board[x][y].hasFlag == true) {}

        if (board[x][y].isRevealed == false and board[x][y].hasMine == false) {
            board[x][y].isRevealed = true;
        }

        if (board[x][y].isRevealed == false and board[x][y].hasMine == true) {
            if (player_action > 1)
            {
                status = finish_loss;
            } else {
                board[x][y].hasMine = false;

                x = (std::rand() % boardwidth);
                y = (std::rand() % boardheight);

                while (board[x][y].hasMine) {
                    x = (std::rand() % boardwidth);
                    y = (std::rand() % boardheight);
                }
                if (board[x][y].hasMine == false) {
                    board[x][y].hasMine = true;
                }

                board[x][y].isRevealed = true;
            }
        }

    }

    bool MinesweeperBoard::isRevealed(int x, int y) const {
        if (board[x][y].isRevealed == true)
            return true;
        if (board[x][y].isRevealed == false)
            return false;
    }

    game_state MinesweeperBoard::getGameState() const {
        return status;
    }

    char MinesweeperBoard::getFieldInfo(int x, int y) const {
        if (x < 0 or y < 0 or x > boardwidth or y > boardheight)
            return '#';

        if (board[x][y].isRevealed == false and board[x][y].hasFlag == true)
            return 'F';

        if (board[x][y].isRevealed == false and board[x][y].hasFlag == false)
            return '_';

        if (board[x][y].isRevealed == true and board[x][y].hasMine == true)
            return 'x';

        if (board[x][y].isRevealed == true and mine_counter(x, y) == 0)
            return ' ';

        if (board[x][y].isRevealed == true and mine_counter(x, y) > 0)
            return 48 + mine_counter(x, y);
    }
