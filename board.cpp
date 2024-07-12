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
            std::cout << get(x, y)->getContent() << ' ';
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
        std::cout << get(x, row)->getContent() << ' ';
    }
}
