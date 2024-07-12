/******************************************************************************
 * inputManager.h                                                             *
 * class hnaling keyboard input including selecting tiles                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <iostream>

#include "board.h"
#include "location.h"

#define CURSOR_UP "\033[1A"
#define CURSOR_DOWN "\033[1B"
#define CURSOR_RIGHT "\033[2C"
#define CURSOR_LEFT "\033[2D"
#define ESCAPE 27
#define UP_ARROW 65
#define DOWN_ARROW 66
#define RIGHT_ARROW 67
#define LEFT_ARROW 68

class InputManager
{
  private:
    void returnCursor(int column);

  public:
    Location *getInput(Board *board);
};

#endif
