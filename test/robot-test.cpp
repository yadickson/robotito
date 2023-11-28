#include "position-mock.hpp"
#include "robot.hpp"

MACRO_TEST_CLASS (Robot)
{

public:
  Position *positionMock;
  Robot *robot;

  MACRO_TEST_SETUP ()
  {
    positionMock = new PositionMock ();
    robot = new Robot (positionMock);
  }

  MACRO_TEST_TEARDOWN ()
  {
    delete positionMock;
    delete robot;
    MACRO_TEST_CLEAR_MOCK ();
  }

  MACRO_TEST_SUITE_START (Robot);
  MACRO_TEST_SUITE_TEST (should_check_position_mock_move_to_left);
  MACRO_TEST_SUITE_TEST (should_check_position_mock_move_to_right);
  MACRO_TEST_SUITE_TEST (should_check_position_mock_move_to_up);
  MACRO_TEST_SUITE_TEST (should_check_position_mock_move_to_down);
  MACRO_TEST_SUITE_TEST (should_check_position);
  MACRO_TEST_SUITE_TEST (should_check_copy_robot_constructor);
  MACRO_TEST_SUITE_TEST (should_check_copy_robot_operator_equeal);
  MACRO_TEST_SUITE_END ();

  MACRO_TEST_METHOD (should_check_position_mock_move_to_left);
  MACRO_TEST_METHOD (should_check_position_mock_move_to_right);
  MACRO_TEST_METHOD (should_check_position_mock_move_to_up);
  MACRO_TEST_METHOD (should_check_position_mock_move_to_down);
  MACRO_TEST_METHOD (should_check_position);
  MACRO_TEST_METHOD (should_check_copy_robot_constructor);
  MACRO_TEST_METHOD (should_check_copy_robot_operator_equeal);
};

MACRO_TEST_REGISTRATION (Robot);

MACRO_TEST (Robot, should_check_position_mock_move_to_left)
{
  const int xFaker = rand () % 100;
  const int expected = xFaker + 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_X_FUNCTION)
      .onObject (positionMock)
      .andReturnValue (xFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_X_FUNCTION)
      .onObject (positionMock)
      .withIntParameter (POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X, expected);

  robot->moveToLeft ();

  mock ().checkExpectations ();
};

MACRO_TEST (Robot, should_check_position_mock_move_to_right)
{
  const int xFaker = rand () % 100;
  const int expected = xFaker - 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_X_FUNCTION)
      .onObject (positionMock)
      .andReturnValue (xFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_X_FUNCTION)
      .onObject (positionMock)
      .withIntParameter (POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X, expected);

  robot->moveToRight ();

  mock ().checkExpectations ();
};

MACRO_TEST (Robot, should_check_position_mock_move_to_up)
{
  const int yFaker = rand () % 100;
  const int expected = yFaker - 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_Y_FUNCTION)
      .onObject (positionMock)
      .andReturnValue (yFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_Y_FUNCTION)
      .onObject (positionMock)
      .withIntParameter (POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y, expected);

  robot->moveToUp ();

  mock ().checkExpectations ();
};

MACRO_TEST (Robot, should_check_position_mock_move_to_down)
{
  const int yFaker = rand () % 100;
  const int expected = yFaker + 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_Y_FUNCTION)
      .onObject (positionMock)
      .andReturnValue (yFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_Y_FUNCTION)
      .onObject (positionMock)
      .withIntParameter (POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y, expected);

  robot->moveToDown ();

  mock ().checkExpectations ();
};

MACRO_TEST (Robot, should_check_position)
{
  const Position *response = robot->getPosition ();
  MACRO_CHECK_EQUAL (positionMock, response);
};

MACRO_TEST (Robot, should_check_copy_robot_constructor)
{
  Robot copyRobot (*robot);

  MACRO_CHECK_EQUAL (positionMock, copyRobot.getPosition ());
};

MACRO_TEST (Robot, should_check_copy_robot_operator_equeal)
{
  Position position (0, 0);
  Robot copyRobot (&position);

  MACRO_CHECK_EQUAL (&position, copyRobot.getPosition ());

  copyRobot = *robot;

  MACRO_CHECK_EQUAL (positionMock, copyRobot.getPosition ());
};

