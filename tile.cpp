/******************************************************************************
 * tile.cpp                                                                   *
 * class representing a tile on a minesweeper board                           *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "tile.h"

Tile::Tile(Location *location)
{
    this->location = location;
    this->content = EMPTY;
    this->opened = false;
}

Tile::~Tile()
{
    delete (location);
}

/* returns if this tile contains a mine                                       */
bool Tile::isMine()
{
    return content == MINE;
}

/* places a mine on this tile, called when the board is initialised           */
void Tile::setMine()
{
    content = MINE;
}

/* calculates and sets the number displayed when the tile is opened           */
void Tile::calculateContent(Board *board)
{
    // mines are already set
    if (isMine())
    {
        return;
    }
    // calculate surrounding mines
    int x = location->getX();
    int y = location->getY();
    int mineCount = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        if (i < 0)
        {
            continue;
        }
        if (i >= board->getWidth())
        {
            break;
        }
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (j < 0)
            {
                continue;
            }
            if (j >= board->getHeight())
            {
                break;
            }
            if (board->get(i, j)->isMine())
            {
                mineCount++;
            }
        }
    }
    // set content
    if (mineCount == 0)
    {
        content = EMPTY;
    }
    else
    {
        content = mineCount + '0';
    }
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

/* returns if there are no mines around the tile                              */
bool Tile::isEmpty()
{
    return content == EMPTY;
}

/* prints the content of the tile to stdout                                   */
void Tile::printContent()
{
    if (opened)
    {
        // set colour
        switch (content)
        {
        case '1':
            std::cout << "\033[34m";
            break;
        case '2':
            std::cout << "\033[32m";
            break;
        case '3':
            std::cout << "\033[31m";
            break;
        case '4':
            std::cout << "\033[35m";
            break;
        case '5':
            std::cout << "\033[33m";
            break;
        case '6':
            std::cout << "\033[36m";
            break;
        }
        // print content
        std::cout << content;
        // reset colour
        std::cout << "\033[0m";
    }
    else
    {
        std::cout << UNOPENED;
    }
}
