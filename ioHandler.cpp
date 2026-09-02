/******************************************************************************
 * ioHandler.cpp                                                              *
 * class handling keyboard input including selecting tiles                    *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "ioHandler.h"

const int IOHandler::ESCAPE = 27;
const int IOHandler::UP_ARROW = 65;
const int IOHandler::DOWN_ARROW = 66;
const int IOHandler::RIGHT_ARROW = 67;
const int IOHandler::LEFT_ARROW = 68;
const char *IOHandler::CLEAR_LINE = "\r\e[K";
const char *IOHandler::CURSOR_UP = "\033[1A";
const char *IOHandler::CURSOR_DOWN = "\033[1B";
const char *IOHandler::CURSOR_RIGHT = "\033[2C";
const char *IOHandler::CURSOR_LEFT = "\033[2D";
const char *IOHandler::BLUE = "\033[34m";
const char *IOHandler::GREEN = "\033[32m";
const char *IOHandler::RED = "\033[31m";
const char *IOHandler::MAGENTA = "\033[35m";
const char *IOHandler::YELLOW = "\033[33m";
const char *IOHandler::CYAN = "\033[36m";

IOHandler::IOHandler()
{
    x = 0;
    y = 0;
}

/* returns the cursor to column                                               */
void IOHandler::returnCursor(int column)
{
    // reset to start of line
    std::cout << "\r";
    for (int i = 0; i < column; i++)
    {
        std::cout << CURSOR_RIGHT;
    }
}

/* returns cursor to the top left of the board                                */
void IOHandler::gotoStart()
{
    std::cout << "\r";
    for (int i = y; i > 0; i--)
    {
        std::cout << CURSOR_UP;
    }
}

/* prints a row of the game board                                             */
void IOHandler::printRow(int row, Board *board)
{
    std::cout << CLEAR_LINE;
    for (int x = 0; x < board->getWidth(); x++)
    {
        Location *location = new Location(x, row);
        Tile *tile = board->get(location);
        // set colour
        switch (tile->getContent())
        {
        case '1':
            std::cout << BLUE;
            break;
        case '2':
            std::cout << GREEN;
            break;
        case '3':
            std::cout << RED;
            break;
        case '4':
            std::cout << MAGENTA;
            break;
        case '5':
            std::cout << YELLOW;
            break;
        case '6':
            std::cout << CYAN;
            break;
        }
        // print content
        std::cout << tile->getContent();
        // reset colour
        std::cout << "\033[0m";
        delete location;
        std::cout << ' ';
    }
};

/* prints the game board                                                      */
void IOHandler::printBoard(Board *board)
{
    for (int y = 0; y < board->getHeight(); y++)
    {
        printRow(y, board);
        std::cout << std::endl;
    }
};

/* moves cursor with arrow keys and returns the selected location             */
Location *IOHandler::getInput(Board *board)
{
    // go to last position
    for (int i = board->getHeight(); i != y; i--)
    {
        std::cout << CURSOR_UP;
    }
    for (int i = 0; i != x; i++)
    {
        std::cout << CURSOR_RIGHT;
    }

    char c;
    while (true)
    {
        std::cin >> c;
        // handle arrow keys
        if (c == ESCAPE)
        {
            std::cin >> c; // ignore middle character
            std::cin >> c;
            // wipe chars printed by arrow key presses
            printRow(y, board);
            returnCursor(x);
            switch (c)
            {
            case UP_ARROW:
                if ((y - 1) >= 0)
                {
                    std::cout << CURSOR_UP;
                    y--;
                }
                break;
            case DOWN_ARROW:
                if ((y + 1) < board->getHeight())
                {
                    std::cout << CURSOR_DOWN;
                    y++;
                }
                break;
            case RIGHT_ARROW:
                if ((x + 1) < board->getWidth())
                {
                    std::cout << CURSOR_RIGHT;
                    x++;
                }
                break;
            case LEFT_ARROW:
                if ((x - 1) >= 0)
                {
                    std::cout << CURSOR_LEFT;
                    x--;
                }
                break;
            }
        }
        else
        {
            break;
        }
    }
    // return location if key wasn't an arrow
    gotoStart();
    return new Location(x, y);
}

/* prints the game                                                            */
void IOHandler::printGame(Board *board)
{
    printBoard(board);
    // TODO: print status bar
};
