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

class Game
{
  private:
    Board *board;

  public:
    Game(int width, int height, int mines);
    void run();
};

#endif
