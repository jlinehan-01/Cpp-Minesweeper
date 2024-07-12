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
    int target;
    int tilesOpened;
    bool solved; // false
    bool alive;  // true
    std::vector<std::vector<Tile *>> tiles;
    void setMines();
    void setTiles();
    void setColour(char content);
    void resetColour();

  public:
    Board(int width, int height, int mines);
    int getWidth();
    int getHeight();
    Tile *get(int column, int row);
    void printBoard();
    bool isSolved();
    bool isAlive();
    void printRow(int row);
    void open(Location *location);
};

#endif
