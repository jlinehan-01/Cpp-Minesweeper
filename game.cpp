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
    this->ioHandler = new IOHandler();
}

Game::~Game()
{
    delete board;
    delete ioHandler;
}

void Game::run()
{
    // initialise board
    ioHandler->printGame(board);
    Location *location;

    // run game
    while (alive && tilesOpened < target)
    {
        location = ioHandler->getInput(board);
        open(location);
        delete location;
        ioHandler->printGame(board);
    }
}

/* handles opening a tile                                                     */
void Game::open(Location *location)
{
    Tile *tile = board->get(location);
    if (tile) // null safety check
    {
        if (tile->open())
        {
            char content = tile->getContent();
            // check if mine was hit
            if (content == Tile::MINE)
            {
                alive = false;
            }
            else
            {
                tilesOpened++;
                // open around empty tiles
                if (content == Tile::EMPTY)
                {
                    openAround(location);
                }
            }
        }
    }
}

/* opens tiles surrounding a tile                                             */
void Game::openAround(Location *location)
{
    int x = location->getX();
    int y = location->getY();
    for (int i = (y - 1); i <= (y + 1); i++)
    {
        for (int j = (x - 1); j <= (x + 1); j++)
        {
            Location *l = new Location(j, i);
            open(l);
            delete l;
        }
    }
}
