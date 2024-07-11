/******************************************************************************
 * main.cpp                                                                   *
 * Main file for running minesweeper game                                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include <iostream>

#include "board.h"
#include "location.h"
#include "tile.h"

int main(int argc, char *argv[])
{
    int width = 30;
    int height = 16;
    int mines = 99;

    Board board = Board(width, height, mines);
    board.printBoard();
    std::cin.ignore();

    return 0;
}
