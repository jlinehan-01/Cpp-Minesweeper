/******************************************************************************
 * board.h                                                                    *
 * class representing a minesweeper board                                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef BOARD_H
#define BOARD_H

class Board;

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "tile.h"

class Board
{
  private:
    int width;
    int height;
    int mines;
    std::vector<std::vector<Tile *>> tiles;
    void setMines();
    void setTiles();

  public:
    Board(int width, int height, int mines);
    int getWidth();
    int getHeight();
    Tile *get(int column, int row);
    void printBoard();
};

#endif
