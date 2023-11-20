#include "table.hpp"

Table::Table (const Table &table)
{
  this->width = table.getWidth ();
  this->height = table.getHeight ();
}

Table::Table (const int width, const int height)
    : width (width), height (height)
{
}

Table::~Table () {}

void
Table::operator= (const Table &table)
{
  this->width = table.getWidth ();
  this->height = table.getHeight ();
}

int
Table::getWidth () const
{
  return this->width;
}

int
Table::getHeight () const
{
  return this->height;
}

bool
Table::canMoveToLeft (const Robot &robot) const
{
  return robot.getPosition ()->getX () < this->width - 4;
}

bool
Table::canMoveToRight (const Robot &robot) const
{
  return robot.getPosition ()->getX () > 1;
}

bool
Table::canMoveToUp (const Robot &robot) const
{
  return robot.getPosition ()->getY () > 1;
}

bool
Table::canMoveToDown (const Robot &robot) const
{
  return robot.getPosition ()->getY () < this->height - 2;
}
