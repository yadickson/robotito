#include "position-mock.cpp"
#include "position-mock.hpp"
#include "position.hpp"
#include "robot.hpp"
#include <CppUTest/MemoryLeakDetectorNewMacros.h>
#include <CppUTest/UtestMacros.h>
#include <CppUTestExt/MockSupport.h>

#include <cstdlib>
#include <memory>

#include "faker-cxx.hpp"

TEST_GROUP (Robot)
{
  std::unique_ptr<FakerCxx> faker;
  std::unique_ptr<Position> positionMock;
  std::unique_ptr<Robot> robot;

  TEST_SETUP ()
  {
    faker = std::make_unique<FakerCxx> ();
    positionMock = std::make_unique<PositionMock> ();
    robot = std::make_unique<Robot> (positionMock.get ());
  }

  TEST_TEARDOWN () { mock ().clear (); }
};

TEST (Robot, should_check_position_mock_move_to_left)
{
  const int xFaker = faker->getNumber (10, 40);
  const int expected = xFaker - 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_X_FUNCTION)
      .onObject (positionMock.get ())
      .andReturnValue (xFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_X_FUNCTION)
      .onObject (positionMock.get ())
      .withIntParameter (POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X, expected);

  robot->moveToLeft ();

  mock ().checkExpectations ();
};

TEST (Robot, should_check_position_mock_move_to_right)
{
  const int xFaker = faker->getNumber (10, 40);
  const int expected = xFaker + 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_X_FUNCTION)
      .onObject (positionMock.get ())
      .andReturnValue (xFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_X_FUNCTION)
      .onObject (positionMock.get ())
      .withIntParameter (POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X, expected);

  robot->moveToRight ();

  mock ().checkExpectations ();
};

TEST (Robot, should_check_position_mock_move_to_up)
{
  const int yFaker = faker->getNumber (10, 40);
  const int expected = yFaker - 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_Y_FUNCTION)
      .onObject (positionMock.get ())
      .andReturnValue (yFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_Y_FUNCTION)
      .onObject (positionMock.get ())
      .withIntParameter (POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y, expected);

  robot->moveToUp ();

  mock ().checkExpectations ();
};

TEST (Robot, should_check_position_mock_move_to_down)
{
  const int yFaker = faker->getNumber (10, 40);
  const int expected = yFaker + 1;

  mock ()
      .expectOneCall (POSITION_MOCK_GET_Y_FUNCTION)
      .onObject (positionMock.get ())
      .andReturnValue (yFaker);

  mock ()
      .expectOneCall (POSITION_MOCK_SET_Y_FUNCTION)
      .onObject (positionMock.get ())
      .withIntParameter (POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y, expected);

  robot->moveToDown ();

  mock ().checkExpectations ();
};

TEST (Robot, should_check_position)
{
  const Position *response = robot->getPosition ();
  CHECK_EQUAL (positionMock.get (), response);
};

TEST (Robot, should_check_copy_robot_constructor)
{
  const Robot copyRobot (*robot);

  CHECK_EQUAL (positionMock.get (), copyRobot.getPosition ());
};

TEST (Robot, should_check_copy_robot_operator_equeal)
{
  Position position (0, 0);
  Robot copyRobot (&position);

  CHECK_EQUAL (&position, copyRobot.getPosition ());

  copyRobot = *robot;

  CHECK_EQUAL (positionMock.get (), copyRobot.getPosition ());
};
