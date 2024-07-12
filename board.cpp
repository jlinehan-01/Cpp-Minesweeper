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

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}

Tile *Board::get(int column, int row)
{
    return tiles.at(row).at(column);
}

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

void Board::printBoard()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            setColour(get(x, y)->getContent());
            std::cout << get(x, y)->getContent() << ' ';
            resetColour();
        }
        std::cout << std::endl;
    }
}

bool Board::isSolved()
{
    return solved;
}

bool Board::isAlive()
{
    return alive;
}

void Board::printRow(int row)
{
    std::cout << CLEAR_LINE;
    for (int x = 0; x < width; x++)
    {
        setColour(get(x, row)->getContent());
        std::cout << get(x, row)->getContent() << ' ';
        resetColour();
    }
}

void Board::setColour(char content)
{
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
}
void Board::resetColour()
{
    std::cout << "\033[0m";
}

void Board::open(Location *location)
{
    Tile *tile = get(location->getX(), location->getY());
    bool openSuccess = tile->open();
    if (openSuccess)
    {
        if (tile->isMine())
        {
            alive = false;
            return;
        }
        else
        {
            tilesOpened++;
            if (tilesOpened == target)
            {
                solved = true;
                return;
            }
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
                        open(new Location(x, y));
                    }
                }
            }
        }
    }
}
