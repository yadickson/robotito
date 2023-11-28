#include "macros-test.hpp"
#include "position.hpp"

MACRO_TEST_CLASS (Position)
{
public:
  int xFaker;
  int yFaker;
  Position *position;

  MACRO_TEST_SETUP ()
  {
    xFaker = rand () % 100;
    yFaker = 200 + rand () % 100;
    position = new Position (xFaker, yFaker);
  }

  MACRO_TEST_TEARDOWN ()
  {
    delete position;
    MACRO_TEST_CLEAR_MOCK ();
  }

  MACRO_TEST_SUITE_START (Position);
  MACRO_TEST_SUITE_TEST (should_check_copy_constructor);
  MACRO_TEST_SUITE_TEST (should_check_equal_operator);
  MACRO_TEST_SUITE_TEST (should_check_position_x);
  MACRO_TEST_SUITE_TEST (should_check_position_y);
  MACRO_TEST_SUITE_TEST (should_check_position_x_updated);
  MACRO_TEST_SUITE_TEST (should_check_position_y_updated);
  MACRO_TEST_SUITE_END ();

  MACRO_TEST_METHOD (should_check_copy_constructor);
  MACRO_TEST_METHOD (should_check_equal_operator);
  MACRO_TEST_METHOD (should_check_position_x);
  MACRO_TEST_METHOD (should_check_position_y);
  MACRO_TEST_METHOD (should_check_position_x_updated);
  MACRO_TEST_METHOD (should_check_position_y_updated);
};

MACRO_TEST_REGISTRATION (Position);

MACRO_TEST (Position, should_check_copy_constructor)
{
  Position copyPosition (*position);

  MACRO_CHECK_EQUAL (xFaker, copyPosition.getX ());
  MACRO_CHECK_EQUAL (yFaker, copyPosition.getY ());
};

MACRO_TEST (Position, should_check_equal_operator)
{
  Position copyPosition (0, 0);

  MACRO_CHECK_EQUAL (0, copyPosition.getX ());
  MACRO_CHECK_EQUAL (0, copyPosition.getY ());

  copyPosition = *position;

  MACRO_CHECK_EQUAL (xFaker, copyPosition.getX ());
  MACRO_CHECK_EQUAL (yFaker, copyPosition.getY ());
};

MACRO_TEST (Position, should_check_position_x)
{
  MACRO_CHECK_EQUAL (xFaker, position->getX ());
};

MACRO_TEST (Position, should_check_position_y)
{
  MACRO_CHECK_EQUAL (yFaker, position->getY ());
};

MACRO_TEST (Position, should_check_position_x_updated)
{
  xFaker = rand () % 100;
  position->setX (xFaker);
  MACRO_CHECK_EQUAL (xFaker, position->getX ());
};

MACRO_TEST (Position, should_check_position_y_updated)
{
  yFaker = rand () % 100;
  position->setY (yFaker);
  MACRO_CHECK_EQUAL (yFaker, position->getY ());
};
