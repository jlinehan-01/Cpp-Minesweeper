/******************************************************************************
 * ioHandler.h                                                                *
 * class handling keyboard input including selecting tiles                    *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include <iostream>

#include "board.h"
#include "location.h"

#define CLEAR_LINE "\r\e[K"
#define CURSOR_UP "\033[1A"
#define CURSOR_DOWN "\033[1B"
#define CURSOR_RIGHT "\033[2C"
#define CURSOR_LEFT "\033[2D"
#define ESCAPE 27
#define UP_ARROW 65
#define DOWN_ARROW 66
#define RIGHT_ARROW 67
#define LEFT_ARROW 68
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

class IOHandler
{
  private:
    int x;
    int y;
    void returnCursor(int column);
    void gotoStart();
    void printRow(int row, Board *board);
    void printBoard(Board *board);

  public:
    IOHandler();
    Location *getInput(Board *board);
    void printGame(Board *board);
};

#endif
