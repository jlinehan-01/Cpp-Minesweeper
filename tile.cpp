/******************************************************************************
 * tile.cpp                                                                   *
 * class representing a tile on a minesweeper board                           *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "tile.h"

const char Tile::MINE = '*';
const char Tile::EMPTY = ' ';

Tile::Tile(Location *location, char content)
{
    this->location = location;
    this->content = content;
    this->opened = false;
}

Tile::~Tile()
{
    delete (location);
}

/* returns the content of the tile                                            */
char Tile::getContent()
{
    return content;
}

/* attempts to open the tile                                                  */
bool Tile::open()
{
    if (!opened)
    {
        opened = true;
        return true;
    }
    else
    {
        return false;
    }
}

/* returns true if this tile has been opened, false otherwise                 */
bool Tile::isOpened()
{
    return opened;
}
