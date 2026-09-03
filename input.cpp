/******************************************************************************
 * input.cpp                                                                  *
 * class representing a player's input. contains an action and a location     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include "input.h"

Input::Input(Location *location, Action action)
{
    this->location = location;
    this->action = action;
}

Input::~Input()
{
    delete location;
}

/* returns the location of the input                                          */
Location *Input::getLocation()
{
    return location;
}

/* returns the action of the input                                            */
Action Input::getAction()
{
    return action;
}
