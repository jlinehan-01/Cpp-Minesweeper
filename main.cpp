/******************************************************************************
 * main.cpp                                                                   *
 * Main file for running minesweeper game                                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <termios.h>

#include "board.h"
#include "inputManager.h"

#define STDIN_FILENO 0
#define WIDTH_ARG 1
#define HEIGHT_ARG 2
#define MINES_ARG 3
#define EXPECTED_NUM_ARGS 4

int main(int argc, char *argv[])
{
    // prevent buffering keystrokes
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    // parse command line arguments
    if (argc != 4)
    {
        std::cout << "usage: ./mines <width> <height> <mines>" << std::endl;
        return -1;
    }
    int width, height, mines;
    sscanf(argv[WIDTH_ARG], "%d", &width);
    sscanf(argv[HEIGHT_ARG], "%d", &height);
    sscanf(argv[MINES_ARG], "%d", &mines);

    // check inputs
    if (width < 1 || height < 1 || mines < 1)
    {
        std::cout << "Must be positive integers" << std::endl;
        return -1;
    }
    if (mines > (width * height))
    {
        std::cout << "Too many mines" << std::endl;
        return -1;
    }

    // initialise board
    Board *board = new Board(width, height, mines);
    InputManager inputManager;
    Location *location;

    // run game
    while (board->isAlive() && !board->isSolved())
    {
        board->printBoard();
        location = inputManager.getInput(board);
        board->open(location);
    }
    board->printBoard();

    return 0;
}
