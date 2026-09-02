/******************************************************************************
 * board.cpp                                                                  *
 * class representing a minesweeper board                                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "board.h"

Board::Board(int width, int height, int mines)
{
    this->width = width;
    this->height = height;
    this->mines = mines;

    // calculate board contents
    char boardChars[height][width];
    memset(boardChars, Tile::EMPTY, sizeof(boardChars));
    // place mines
    // enumerate locations
    std::vector<Location *> locations;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            locations.push_back(new Location(j, i));
        }
    }
    // choose locations for mines
    srand(time(NULL));
    for (int i = 0; i < mines; i++)
    {
        int j = rand() % locations.size();
        boardChars[locations.at(j)->getY()][locations.at(j)->getX()] =
            Tile::MINE;
        delete locations.at(j);
        locations.erase(locations.begin() + j);
    }
    for (Location *location : locations)
    {
        delete location;
    }

    // calculate numbers
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (boardChars[y][x] == Tile::MINE)
            {
                continue;
            }
            int surroundingMines = 0;
            for (int i = y - 1; i <= y + 1; i++)
            {
                if (i < 0 || i >= height)
                {
                    continue;
                }
                for (int j = x - 1; j <= x + 1; j++)
                {
                    if (j < 0 || j >= width)
                    {
                        continue;
                    }
                    if (boardChars[i][j] == Tile::MINE)
                    {
                        surroundingMines++;
                    }
                }
            }
            if (surroundingMines == 0)
            {
                boardChars[y][x] = Tile::EMPTY;
            }
            else
            {
                boardChars[y][x] = '0' + surroundingMines;
            }
        }
    }

    // generate tiles
    for (int y = 0; y < height; y++)
    {
        tiles.push_back(std::vector<Tile *>());
        for (int x = 0; x < width; x++)
        {
            tiles.at(y).push_back(
                new Tile(new Location(x, y), boardChars[y][x]));
        }
    }
}

Board::~Board()
{
    Location *location;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            location = new Location(x, y);
            delete get(location);
            delete location;
        }
    }
}

/* returns the width of the board                                             */
int Board::getWidth()
{
    return width;
}

/* returns the height of the board                                            */
int Board::getHeight()
{
    return height;
}

/* returns a pointer to the Tile at the specified location                    */
Tile *Board::get(Location *location)
{
    int column = location->getX();
    int row = location->getY();
    // check location is valid
    if (row < 0 || row >= height || column < 0 || column >= width)
    {
        return NULL;
    }
    return tiles.at(row).at(column);
}
