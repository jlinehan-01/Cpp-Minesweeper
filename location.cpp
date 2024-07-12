/******************************************************************************
 * location.cpp                                                               *
 * class representing a location on a minesweeper board                       *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "location.h"

Location::Location(int x, int y)
{
    this->x = x;
    this->y = y;
}

/* returns the x coordinate of the Location                                   */
int Location::getX()
{
    return x;
}

/* returns the y coordinate of the Location                                   */
int Location::getY()
{
    return y;
}
