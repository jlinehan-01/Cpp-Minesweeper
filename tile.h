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
    static constexpr char UNOPENED = '#';

    Location *location;
    char content;
    bool opened;  // false
    bool flagged; // false

  public:
    static constexpr char MINE = '*';
    static constexpr char FLAG = 'F';
    static constexpr char EMPTY = ' ';

    Tile(Location *location, char content);
    ~Tile();
    char getContent();
    bool open();
    bool flag();
};

#endif
