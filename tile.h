/******************************************************************************
 * tile.h                                                                     *
 * class representing a tile on a minesweeper board                           *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef TILE_H
#define TILE_H

class Tile;

#include "board.h"
#include "location.h"

#include <iostream>

#define UNOPENED '#'

class Tile
{
  private:
    Location *location;
    char content;
    bool opened; // false

  public:
    static const char MINE;
    static const char EMPTY;

    Tile(Location *location);
    ~Tile();
    char getContent();
    bool isMine();
    void setMine();
    void calculateContent(Board *board);
    bool open();
    bool isEmpty();
    void printContent();
};

#endif
