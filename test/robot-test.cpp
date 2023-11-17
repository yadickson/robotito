#include <CppUTest/TestHarness.h>

#include "robot.hpp"

TEST_GROUP (Robot)
{

public:
  int xFaker;
  int yFaker;
  Position *position;
  Robot *robot;

protected:
  void setup () {}

  void teardown () {}
};

TEST (Robot, should_check_equal_operator){

};
