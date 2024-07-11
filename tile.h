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

class Tile
{
  private:
    Location *location;
    char content;

  public:
    Tile(Location *location);
    char getContent();
    bool isMine();
    void setMine();
    void calculateContent(Board *board);
};

#endif
