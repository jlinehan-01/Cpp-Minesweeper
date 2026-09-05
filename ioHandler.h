/******************************************************************************
 * ioHandler.h                                                                *
 * class handling keyboard input including selecting tiles                    *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include <functional>
#include <iomanip>
#include <iostream>

#include "board.h"
#include "input.h"
#include "location.h"
#include "tile.h"

class IOHandler
{
  private:
    static constexpr const int STATUS_BAR_HEIGHT = 1;
    static constexpr const int MINE_COUNT_WIDTH = 2;
    static constexpr const int ESCAPE = 27;
    static constexpr const int UP_ARROW = 65;
    static constexpr const int DOWN_ARROW = 66;
    static constexpr const int RIGHT_ARROW = 67;
    static constexpr const int LEFT_ARROW = 68;
    static constexpr const char OPEN_KEY = 'z';
    static constexpr const char FLAG_KEY = 'x';
    static constexpr const char *CLEAR_LINE = "\r\e[K";
    static constexpr const char *CURSOR_UP = "\033[1A";
    static constexpr const char *CURSOR_DOWN = "\033[1B";
    static constexpr const char *CURSOR_RIGHT = "\033[2C";
    static constexpr const char *CURSOR_LEFT = "\033[2D";
    static constexpr const char *BLUE = "\033[34m";
    static constexpr const char *GREEN = "\033[32m";
    static constexpr const char *RED = "\033[31m";
    static constexpr const char *MAGENTA = "\033[35m";
    static constexpr const char *YELLOW = "\033[33m";
    static constexpr const char *CYAN = "\033[36m";
    static constexpr const char *FLAG_COLOUR = "\e[41m";

    int x;
    int y;
    std::function<int()> mines;
    void returnCursor(int column);
    void gotoStart();
    void printRow(int row, Board *board);
    void printBoard(Board *board);
    void printStatusBar();

  public:
    IOHandler(std::function<int()> mines);
    Input *getInput(Board *board);
    void printGame(Board *board);
};

#endif
