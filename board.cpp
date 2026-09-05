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

    // generate placeholder tiles
    for (int y = 0; y < height; y++)
    {
        tiles.push_back(std::vector<Tile *>());
        for (int x = 0; x < width; x++)
        {
            tiles.at(y).push_back(new Tile(Tile::EMPTY));
        }
    }
}

Board::~Board()
{
    for (std::vector<Tile *> row : tiles)
    {
        for (Tile *tile : row)
        {
            delete tile;
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

/* generates tile content with no mines around first move                     */
void Board::initialise(Location *firstMove)
{
    int column = firstMove->getX();
    int row = firstMove->getY();
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
            // dont add around first move
            if (i >= row - 1 && i <= row + 1 && j >= column - 1 &&
                j <= column + 1)
            {
                continue;
            }
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
    for (Location *_location : locations)
    {
        delete _location;
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

    // replace placeholder tiles
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            delete tiles.at(y).at(x);
            tiles.at(y).at(x) = new Tile(boardChars[y][x]);
        }
    }
}
