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

#include "location.h"
#include "tile.h"

#define CLEAR_LINE "\r\e[K"

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
    ~Board();
    int getWidth();
    int getHeight();
    Tile *get(Location *location);
    void printBoard();
    void printRow(int row);
    char open(Location *location);
};

#endif
