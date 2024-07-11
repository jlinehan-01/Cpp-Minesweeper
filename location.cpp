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

int Location::getX()
{
    return x;
}

int Location::getY()
{
    return y;
}
