#include "position.hpp"

Position::Position () : x (0), y (0) {}

Position::Position (const Position &position)
    : x (position.getX ()), y (position.getY ())
{
}

Position::Position (const int x, const int y) : x (x), y (y) {}

auto
Position::operator= (const Position &position) -> Position &
{
  this->x = position.getX ();
  this->y = position.getY ();
  return *this;
}

Position::~Position () = default;

auto
Position::getX () const -> int
{
  return this->x;
}

auto
Position::getY () const -> int
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
