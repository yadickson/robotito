#include "position-test.hpp"

void
PositionTest::setUp ()
{
  position = new Position (11, 2);
}

void
PositionTest::tearDown ()
{
  delete position;
}

void
PositionTest::should_check_position_x ()
{
  CPPUNIT_ASSERT_EQUAL (11, position->getX ());
}

void
PositionTest::should_check_position_y ()
{
  CPPUNIT_ASSERT_EQUAL (2, position->getY ());
}
