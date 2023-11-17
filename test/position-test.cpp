#include <CppUTest/TestHarness.h>

#include "position.hpp"

TEST_GROUP (Position)
{

public:
  int xFaker;
  int yFaker;
  Position *position;

protected:
  void setup ()
  {
    xFaker = rand () % 100;
    yFaker = 200 + rand () % 100;
    position = new Position (xFaker, yFaker);
  }

  void teardown () { delete position; }
};

TEST (Position, should_check_equal_operator)
{
  Position copyPosition = *position;

  CHECK (&copyPosition != position);
  CHECK_EQUAL (xFaker, copyPosition.getX ());
  CHECK_EQUAL (yFaker, copyPosition.getY ());
};

TEST (Position, should_check_position_x)
{
  CHECK_EQUAL (xFaker, position->getX ());
};

TEST (Position, should_check_position_y)
{
  CHECK_EQUAL (yFaker, position->getY ());
};

TEST (Position, should_check_position_x_updated)
{
  xFaker = rand () % 100;
  position->setX (xFaker);
  CHECK_EQUAL (xFaker, position->getX ());
};

TEST (Position, should_check_position_y_updated)
{
  yFaker = rand () % 100;
  position->setY (yFaker);
  CHECK_EQUAL (yFaker, position->getY ());
};
