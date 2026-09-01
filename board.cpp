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
    // generate tiles
    for (int y = 0; y < height; y++)
    {
        tiles.push_back(std::vector<Tile *>());
        for (int x = 0; x < width; x++)
        {
            tiles.at(y).push_back(new Tile(new Location(x, y)));
        }
    }
    setMines();
    setTiles();
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

/* designates tiles to be mines                                               */
void Board::setMines()
{
    int minesSet = 0;
    srand(time(NULL));
    while (minesSet < mines)
    {
        int x = rand() % width;
        int y = rand() % height;
        Location *location = new Location(x, y);
        if (!(get(location)->isMine()))
        {
            get(location)->setMine();
            minesSet++;
        }
        delete location;
    }
}

/* sets the contents of each Tile                                             */
void Board::setTiles()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Location *location = new Location(i, j);
            get(location)->calculateContent(this);
            delete location;
        }
    }
}

/* prints the board to stdout                                                 */
void Board::printBoard()
{
    for (int y = 0; y < height; y++)
    {
        printRow(y);
        std::cout << std::endl;
    }
}

/* prints a specific row of the board. used to overwrite keyboard input       */
void Board::printRow(int row)
{
    std::cout << CLEAR_LINE;
    for (int x = 0; x < width; x++)
    {
        Location *location = new Location(x, row);
        get(location)->printContent();
        delete location;
        std::cout << ' ';
    }
}
