/******************************************************************************
 * location.h                                                                 *
 * class representing a location on a minesweeper board                       *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#ifndef LOCATION_H
#define LOCATION_H

class Location;

class Location
{
  private:
    int x;
    int y;

  public:
    Location(int x, int y);
    int getX();
    int getY();
};

#endif
