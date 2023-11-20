#include <CppUTest/TestHarness.h>

#include "position.hpp"

TEST_GROUP (Position)
{

public:
  int xFaker;
  int yFaker;
  Position *position;

protected:
  TEST_SETUP ()
  {
    xFaker = rand () % 100;
    yFaker = 200 + rand () % 100;
    position = new Position (xFaker, yFaker);
  }

  TEST_TEARDOWN () { delete position; }
};

TEST (Position, should_check_copy_constructor)
{
  Position copyPosition (*position);

  CHECK_EQUAL (xFaker, copyPosition.getX ());
  CHECK_EQUAL (yFaker, copyPosition.getY ());
};

TEST (Position, should_check_equal_operator)
{
  Position copyPosition (0, 0);

  CHECK_EQUAL (0, copyPosition.getX ());
  CHECK_EQUAL (0, copyPosition.getY ());

  copyPosition = *position;

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
