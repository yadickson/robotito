#include "robot.hpp"
#include "position.hpp"

Robot::Robot (Position *position, const char *image)
{
  this->position = position;
  this->image.assign (image);
}

Robot::Robot (Robot &robot)
{
  this->position = robot.position;
  this->image = robot.image;
}

void
Robot::operator= (const Robot &robot)
{
  this->position = robot.position;
  this->image = robot.image;
}

Robot::~Robot () {}

Position *
Robot::getPosition () const
{
  return this->position;
}

const char *
Robot::getImage () const
{
  return this->image.c_str ();
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
