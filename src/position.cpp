#include "position.hpp"

Position::Position (const Position &position)
{
  this->x = position.getX ();
  this->y = position.getY ();
}

Position::Position (const int x, const int y) : x (x), y (y) {}

void
Position::operator= (const Position &position)
{
  this->x = position.getX ();
  this->y = position.getY ();
}

Position::~Position () {}

int
Position::getX () const
{
  return this->x;
}

int
Position::getY () const
{
  return this->y;
}

void
Position::setX (const int x)
{
  this->x = x;
}

void
Position::setY (const int y)
{
  this->y = y;
}
