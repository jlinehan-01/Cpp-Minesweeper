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
