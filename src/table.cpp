#include <ncurses.h>

#include "table.hpp"

Table::~Table () {}

bool
Table::canMoveToRight (const Robot &robot) const
{
  return robot.getPosition ()->getX () < COLS - 3;
}

bool
Table::canMoveToLeft (const Robot &robot) const
{
  return robot.getPosition ()->getX () > 2;
}

bool
Table::canMoveToUp (const Robot &robot) const
{
  return robot.getPosition ()->getY () > 1;
}

bool
Table::canMoveToDown (const Robot &robot) const
{
  return robot.getPosition ()->getY () < LINES - 2;
}
