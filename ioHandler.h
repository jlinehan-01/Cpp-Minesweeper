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

class IOHandler
{
  private:
    static const int ESCAPE;
    static const int UP_ARROW;
    static const int DOWN_ARROW;
    static const int RIGHT_ARROW;
    static const int LEFT_ARROW;
    static const char *CLEAR_LINE;
    static const char *CURSOR_UP;
    static const char *CURSOR_DOWN;
    static const char *CURSOR_RIGHT;
    static const char *CURSOR_LEFT;
    static const char *BLUE;
    static const char *GREEN;
    static const char *RED;
    static const char *MAGENTA;
    static const char *YELLOW;
    static const char *CYAN;

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
