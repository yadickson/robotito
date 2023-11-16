#include "position.hpp"

Position::Position (int x, int y) : x (x), y (y) {}

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
