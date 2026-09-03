/******************************************************************************
 * input.h                                                                    *
 * class representing a player's input. contains an action and a location     *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef INPUT_H
#define INPUT_H

#include "location.h"

class Input;

enum class Action
{
    OPEN,
    FLAG
};

class Input
{
  private:
    Location *location;
    Action action;

  public:
    Input(Location *location, Action action);
    ~Input();
    Location *getLocation();
    Action getAction();
};

#endif
