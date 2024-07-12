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

#define MINE '*'
#define EMPTY ' '
#define UNOPENED '#'

class Tile
{
  private:
    Location *location;
    char content;
    bool opened; // false

  public:
    Tile(Location *location);
    bool isMine();
    void setMine();
    void calculateContent(Board *board);
    bool open();
    bool isEmpty();
    void printContent();
};

#endif
