#include "robot.hpp"
#include "position.hpp"

Robot::Robot (Position *position) : position (position) {}

Robot::Robot (const Robot &robot) : position (robot.getPosition ()) {}

auto
Robot::operator= (const Robot &robot) -> Robot &
{
  this->position = robot.getPosition ();
  return *this;
}

Robot::~Robot () = default;

auto
Robot::getPosition () const -> Position *
{
  return this->position;
}

void
Robot::moveToLeft ()
{
  const int x = position->getX ();
  this->position->setX (x - 1);
}

void
Robot::moveToRight ()
{
  const int x = position->getX ();
  this->position->setX (x + 1);
}

void
Robot::moveToUp ()
{
  const int y = position->getY ();
  this->position->setY (y - 1);
}

void
Robot::moveToDown ()
{
  const int y = position->getY ();
  this->position->setY (y + 1);
}
