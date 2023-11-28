#include "table.hpp"

Table::Table (Display *display) { this->display = display; }

Table::Table (const Table &table) { this->display = table.display; }

Table::~Table () {}

void
Table::operator= (const Table &table)
{
  this->display = table.display;
}

bool
Table::canMoveToLeft (const Robot &robot) const
{
  return robot.getPosition ()->getX () < this->display->getWidth () - 3;
}

bool
Table::canMoveToRight (const Robot &robot) const
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
  return robot.getPosition ()->getY () < this->display->getHeight () - 2;
}
