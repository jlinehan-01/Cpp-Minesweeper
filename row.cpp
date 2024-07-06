/******************************************************************************
 * row.cpp                                                                    *
 * helper class representing a row of tiles on a minesweeper board            *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "row.h"

Row::Row(int width, int rowNum)
{
    this->width = width;
    tiles = (Tile **)malloc(sizeof(Tile *) * width);
    assert(tiles);
    for (int i = 0; i < width; i++)
    {
        tiles[i] = new Tile(new Location(i, rowNum));
    }
}

/*Row::~Row()
{
    for (int i = 0; i < width; i++)
    {
        delete(tiles[i]);
    }
    delete(tiles);
}*/

Tile *Row::get(int column)
{
    return tiles[column];
}
