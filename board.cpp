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
    this->target = (width * height) - mines;
    this->tilesOpened = 0;
    this->solved = false;
    this->alive = true;
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
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            delete (get(x, y));
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
Tile *Board::get(int column, int row)
{
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
        if (!(get(x, y)->isMine()))
        {
            get(x, y)->setMine();
            minesSet++;
        }
    }
}

/* sets the contents of each Tile                                             */
void Board::setTiles()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            get(i, j)->calculateContent(this);
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

/* returns if the game has been finished                                      */
bool Board::isSolved()
{
    return solved;
}

/* returns if a mine has been hit                                             */
bool Board::isAlive()
{
    return alive;
}

/* prints a specific row of the board. used to overwrite keyboard input       */
void Board::printRow(int row)
{
    std::cout << CLEAR_LINE;
    for (int x = 0; x < width; x++)
    {
        get(x, row)->printContent();
        std::cout << ' ';
    }
}

/* opens the tile at location                                                 */
void Board::open(Location *location)
{
    Tile *tile = get(location->getX(), location->getY());
    // ensure tile was opened
    bool openSuccess = tile->open();
    if (openSuccess)
    {
        // check if we hit a mine
        if (tile->isMine())
        {
            alive = false;
            return;
        }
        else
        {
            // check for win
            tilesOpened++;
            if (tilesOpened == target)
            {
                solved = true;
                return;
            }
            // check for empty tile
            if (tile->isEmpty())
            {
                for (int y = location->getY() - 1; y <= location->getY() + 1;
                     y++)
                {
                    if (y < 0 || y >= height)
                    {
                        continue;
                    }
                    for (int x = location->getX() - 1;
                         x <= location->getX() + 1; x++)
                    {
                        if (x < 0 || x >= width)
                        {
                            continue;
                        }
                        Location *location = new Location(x, y);
                        open(location);
                        delete (location);
                    }
                }
            }
        }
    }
}
