/******************************************************************************
 * tile.cpp                                                                   *
 * class representing a tile on a minesweeper board                           *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "tile.h"

const char Tile::UNOPENED = '#';
const char Tile::FLAG = 'F';
const char Tile::MINE = '*';
const char Tile::EMPTY = ' ';

Tile::Tile(Location *location, char content)
{
    this->location = location;
    this->content = content;
    this->opened = false;
    this->flagged = false;
}

Tile::~Tile()
{
    delete (location);
}

/* returns the content of the tile                                            */
char Tile::getContent()
{
    if (opened)
    {
        return content;
    }
    else if (flagged)
    {
        return FLAG;
    }
    else
    {
        return UNOPENED;
    }
}

/* attempts to open the tile                                                  */
bool Tile::open()
{
    if (!opened)
    {
        if (!flagged)
        {
            opened = true;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/* toggles the tile's flag state                                              */
bool Tile::flag()
{
    if (!opened)
    {
        flagged = !flagged;
        return true;
    }
    else
    {
        return false;
    }
}
