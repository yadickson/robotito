#include <CppUTest/TestHarness.h>

#include "position-mock.hpp"
#include "robot.hpp"

TEST_GROUP (Robot)
{

public:
  Position *positionMock;
  Robot *robot;

protected:
  TEST_SETUP ()
  {
    positionMock = new PositionMock ();
    robot = new Robot (positionMock);
  }

  TEST_TEARDOWN ()
  {
    delete positionMock;
    delete robot;
    mock ().clear ();
  }
};

TEST (Robot, should_check_position_mock_move_to_left)
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

TEST (Robot, should_check_position_mock_move_to_right)
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

TEST (Robot, should_check_position_mock_move_to_up)
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

TEST (Robot, should_check_position_mock_move_to_down)
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

TEST (Robot, should_check_position)
{
  const Position *response = robot->getPosition ();
  CHECK_EQUAL (positionMock, response);
};

TEST (Robot, should_check_copy_robot_constructor)
{
  Robot copyRobot (*robot);

  const Position *response = copyRobot.getPosition ();
  CHECK_EQUAL (positionMock, response);
};

TEST (Robot, should_check_copy_robot_operator_equeal)
{
  Position position (0, 0);
  Robot copyRobot (&position);

  const Position *response = copyRobot.getPosition ();
  CHECK_EQUAL (&position, response);

  copyRobot = *robot;

  const Position *nextResponse = copyRobot.getPosition ();
  CHECK_EQUAL (positionMock, nextResponse);
};
