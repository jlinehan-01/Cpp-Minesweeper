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
    rows = (Row **)malloc(sizeof(Row *) * height);
    assert(rows);
    for (int i = 0; i < height; i++)
    {
        rows[i] = new Row(width, i);
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
    return rows[row]->get(column);
}

void Board::setMines()
{
    int minesSet = 0;
    srand(time(NULL));
    while (minesSet < mines)
    {
        int x = rand() % width;
        int y = rand() % height;
        if (!(rows[y]->get(x)->isMine()))
        {
            rows[y]->get(x)->setMine();
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
