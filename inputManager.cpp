/******************************************************************************
 * inputManager.cpp                                                           *
 * class hnaling keyboard input including selecting tiles                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "inputManager.h"

InputManager::InputManager()
{
    x = 0;
    y = 0;
}

/* returns the cursor to column                                               */
void InputManager::returnCursor(int column)
{
    // reset to start of line
    std::cout << "\r";
    for (int i = 0; i < column; i++)
    {
        std::cout << CURSOR_RIGHT;
    }
}

/* moves cursor with arrow keys and returns the selected location             */
Location *InputManager::getInput(Board *board)
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
            board->printRow(y);
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
    // return location if key wasnt an arrow
    gotoStart();
    return new Location(x, y);
}

/* returns cursor to the top left of the board                                */
void InputManager::gotoStart()
{
    std::cout << "\r";
    for (int i = y; i > 0; i--)
    {
        std::cout << CURSOR_UP;
    }
}
