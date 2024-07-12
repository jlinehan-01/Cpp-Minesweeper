/******************************************************************************
 * inputManager.cpp                                                           *
 * class hnaling keyboard input including selecting tiles                     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "inputManager.h"

void InputManager::returnCursor(int column)
{
    // reset to start of line
    std::cout << "\r";
    for (int i = 0; i < column; i++)
    {
        std::cout << CURSOR_RIGHT;
    }
}

Location *InputManager::getInput(Board *board)
{
    // move cursor onto board
    std::cout << CURSOR_UP;
    // record coordinates
    int x = 0;
    int y = board->getHeight() - 1;

    char c;
    while (true)
    {
        std::cin >> c;
        if (c == ESCAPE)
        {
            std::cin >> c; // ignore middle character
            std::cin >> c;
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
    return new Location(x, y);
}
