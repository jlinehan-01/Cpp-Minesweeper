/******************************************************************************
 * game.cpp                                                                   *
 * class representing a single game of minesweeper                            *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "game.h"

Game::Game(int width, int height, int mines)
{
    board = new Board(width, height, mines);
}

void Game::run()
{
    // initialise board
    IOHandler ioHandler;
    Location *location;

    // run game
    while (board->isAlive() && !board->isSolved())
    {
        board->printBoard();
        location = ioHandler.getInput(board);
        board->open(location);
        delete (location);
    }
    board->printBoard();

    // free memory
    delete (board);
}
