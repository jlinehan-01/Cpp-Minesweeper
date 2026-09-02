/******************************************************************************
 * game.h                                                                     *
 * class representing a single game of minesweeper                            *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef GAME_H
#define GAME_H

class Game;

#include "board.h"
#include "ioHandler.h"
#include "location.h"
#include "tile.h"

class Game
{
  private:
    Board *board;
    int target;
    int tilesOpened;
    bool solved; // false
    bool alive;  // true
    IOHandler *ioHandler;
    void open(Location *location);
    void openAround(Location *location);

  public:
    Game(int width, int height, int mines);
    ~Game();
    void run();
};

#endif
