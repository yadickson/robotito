#include "position.hpp"

Position::Position (const int x, const int y) : x (x), y (y) {}

void
Position::operator= (const Position &position)
{
  this->x = position.x;
  this->y = position.y;
}

Position::~Position () {}

int
Position::getX ()
{
  return this->x;
}

int
Position::getY ()
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
