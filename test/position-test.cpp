#include "position.hpp"
#include <CppUTest/MemoryLeakDetectorNewMacros.h>
#include <CppUTest/UtestMacros.h>
#include <CppUTestExt/MockSupport.h>
#include <memory>

#include "faker-cxx.hpp"

TEST_GROUP (Position)
{
  int xFaker;
  int yFaker;
  std::unique_ptr<FakerCxx> faker;
  std::unique_ptr<Position> position;

  TEST_SETUP ()
  {
    faker = std::make_unique<FakerCxx> ();
    xFaker = faker->getNumber (20, 40);
    yFaker = faker->getNumber (40, 100);
    position = std::make_unique<Position> (xFaker, yFaker);
  }

  TEST_TEARDOWN () { mock ().clear (); }
};

TEST (Position, should_check_copy_constructor)
{
  const Position copyPosition (*position);

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
  xFaker = faker->getNumber (200, 400);
  position->setX (xFaker);
  CHECK_EQUAL (xFaker, position->getX ());
};

TEST (Position, should_check_position_y_updated)
{
  yFaker = faker->getNumber (200, 400);
  position->setY (yFaker);
  CHECK_EQUAL (yFaker, position->getY ());
};
