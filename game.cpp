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
    this->board = new Board(width, height, mines);
    this->target = (width * height) - mines;
    this->tilesOpened = 0;
    this->solved = false;
    this->alive = true;
}

Game::~Game()
{
    delete board;
}

void Game::run()
{
    // initialise board
    IOHandler ioHandler;
    Location *location;

    // run game
    while (alive && tilesOpened < target)
    {
        board->printBoard();
        location = ioHandler.getInput(board);
        Tile *tile = board->get(location);
        if (tile->open())
        {
            char content = tile->getContent();
            if (content == Tile::MINE)
            {
                alive = false;
            }
            else
            {
                tilesOpened++;
            }
        }
        delete (location);
    }
    board->printBoard();
}
