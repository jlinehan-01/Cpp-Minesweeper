/******************************************************************************
 * main.cpp                                                                   *
 * Main file for running minesweeper game                                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include <iostream>
#include <termios.h>
#define STDIN_FILENO 0
#include <stdlib.h>

#include "board.h"
#include "inputManager.h"

int main(int argc, char *argv[])
{
    // prevent buffering keystrokes
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    int width = 9;
    int height = 9;
    int mines = 10;

    Board *board = new Board(width, height, mines);
    InputManager inputManager;
    Location *location;

    while (board->isAlive() && !board->isSolved())
    {
        board->printBoard();
        location = inputManager.getInput(board);
        board->open(location);
    }
    board->printBoard();

    return 0;
}
