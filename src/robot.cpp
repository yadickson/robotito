#include "robot.hpp"

Robot::Robot (Position *position) { this->position = position; }
Robot *
Robot::operator= (const Robot *robot)
{
  this->position = robot->position;
  return this;
}

Robot::~Robot () { delete position; }

Position *
Robot::getPosition ()
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
}

void
Robot::moveToUp ()
{
}

void
Robot::moveToDown ()
{
}
