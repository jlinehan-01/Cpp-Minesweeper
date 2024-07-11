/******************************************************************************
 * row.h                                                                      *
 * helper class representing a row of tiles on a minesweeper board            *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef ROW_H
#define ROW_H

class Row;

#include <cstdlib>

#include "location.h"
#include "tile.h"

class Row
{
  private:
    int width;
    Tile **tiles;

  public:
    Row(int width, int rowNum);
    //~Row();
    Tile *get(int column);
};

#endif
