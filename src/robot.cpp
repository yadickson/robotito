#include "robot.hpp"
#include "position.hpp"

Robot::Robot (Position *position) { this->position = position; }

Robot::Robot (const Robot &robot) { this->position = robot.position; }

void
Robot::operator= (const Robot &robot)
{
  this->position = robot.position;
}

Robot::~Robot () {}

Position *
Robot::getPosition () const
{
  return this->position;
}

void
Robot::moveToLeft ()
{
  const int x = position->getX ();
  this->position->setX (x + 1);
}

void
Robot::moveToRight ()
{
  const int x = position->getX ();
  this->position->setX (x - 1);
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
