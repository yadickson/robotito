#pragma once

#include <cppunit/extensions/HelperMacros.h>
#include "position.hpp"

class PositionTest : public CPPUNIT_NS::TestFixture  {

  CPPUNIT_TEST_SUITE(PositionTest);
  CPPUNIT_TEST(should_check_position_x);
  CPPUNIT_TEST(should_check_position_y);
  CPPUNIT_TEST_SUITE_END();

private:
  Position *position;
public:
  void setUp();
  void tearDown();
protected:
  void should_check_position_x();
  void should_check_position_y();
};

CPPUNIT_TEST_SUITE_REGISTRATION( PositionTest );
