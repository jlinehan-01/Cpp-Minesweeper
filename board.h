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
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

#include "location.h"
#include "tile.h"

class Board
{
  private:
    int width;
    int height;
    int mines;
    std::vector<std::vector<Tile *>> tiles;

  public:
    Board(int width, int height, int mines);
    ~Board();
    int getWidth();
    int getHeight();
    Tile *get(Location *location);
    char open(Location *location);
};

#endif
