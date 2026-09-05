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

#include <functional>

#include "board.h"
#include "ioHandler.h"
#include "location.h"
#include "tile.h"

class Game
{
  private:
    Board *board;
    int target;
    int tilesOpened;    // 0
    int flags;          // 0
    bool alive;         // true
    bool firstMoveMade; // false
    IOHandler *ioHandler;
    void open(Location *location);
    void openAround(Location *location);
    void flag(Location *location);

  public:
    Game(int width, int height, int mines);
    ~Game();
    void run();
};

#endif
