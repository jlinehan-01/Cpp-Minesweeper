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
}

char Tile::getContent()
{
    return content;
}

bool Tile::isMine()
{
    return content == MINE;
}

void Tile::setMine()
{
    content = MINE;
}

void Tile::calculateContent(Board *board)
{
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
        char _content[10];
        sprintf(_content, "%d", mineCount);
        content = _content[0];
    }
}
