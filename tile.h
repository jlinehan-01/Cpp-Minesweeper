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

class Tile
{
  private:
    static const char UNOPENED;
    static const char FLAG;

    Location *location;
    char content;
    bool opened;  // false
    bool flagged; // false

  public:
    static const char MINE;
    static const char EMPTY;

    Tile(Location *location, char content);
    ~Tile();
    char getContent();
    bool open();
    bool flag();
};

#endif
