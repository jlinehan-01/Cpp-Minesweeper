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
    this->flags = 0;
    this->solved = false;
    this->alive = true;
    this->ioHandler = new IOHandler([this, mines]() { return mines - flags; });
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
    Input *input;

    // run game
    while (alive && tilesOpened < target)
    {
        input = ioHandler->getInput(board);
        switch (input->getAction())
        {
        case Action::OPEN:
            open(input->getLocation());
            break;
        case Action::FLAG:
            flag(input->getLocation());
            break;
        }
        delete input;
        ioHandler->printGame(board);
    }
}

/* handles opening a tile                                                     */
void Game::open(Location *location)
{
    Tile *tile = board->get(location);
    if (tile) // null safety check
    {
        bool tileOpened = tile->open();
        char content = tile->getContent();
        if (tileOpened)
        {
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
        // open around appropriately flagged numbers
        else
        {
            if (content != Tile::FLAG && content != Tile::EMPTY)
            {
                // count flags around tile
                int flags = 0;
                int x = location->getX();
                int y = location->getY();
                for (int i = (y - 1); i <= (y + 1); i++)
                {
                    for (int j = (x - 1); j <= (x + 1); j++)
                    {
                        Location *l = new Location(j, i);
                        Tile *_tile = board->get(l);
                        if (_tile)
                        {
                            if (_tile->getContent() == Tile::FLAG)
                            {
                                flags++;
                            }
                        }
                        delete l;
                    }
                }
                // open around tile
                if (tile->getContent() - '0' == flags)
                {
                    for (int i = (y - 1); i <= (y + 1); i++)
                    {
                        for (int j = (x - 1); j <= (x + 1); j++)
                        {
                            Location *l = new Location(j, i);
                            Tile *_tile = board->get(l);
                            if (_tile)
                            {
                                tileOpened = _tile->open();
                                content = _tile->getContent();
                                if (tileOpened)
                                {
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
                                            openAround(l);
                                        }
                                    }
                                }
                            }
                            delete l;
                        }
                    }
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

/* flags a tile                                                               */
void Game::flag(Location *location)
{
    Tile *tile = board->get(location);
    if (tile->flag())
    {
        if (tile->isFlagged())
        {
            flags++;
        }
        else
        {
            flags--;
        }
    }
}
