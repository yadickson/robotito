#include <ncurses.h>

#include "table.hpp"

Table::~Table () = default;

auto
Table::canMoveToRight (const Robot &robot) const -> bool
{
  return robot.getPosition ()->getX () < COLS - 3;
}

auto
Table::canMoveToLeft (const Robot &robot) const -> bool
{
  return robot.getPosition ()->getX () > 2;
}

auto
Table::canMoveToUp (const Robot &robot) const -> bool
{
  return robot.getPosition ()->getY () > 1;
}

auto
Table::canMoveToDown (const Robot &robot) const -> bool
{
  return robot.getPosition ()->getY () < LINES - 2;
}
