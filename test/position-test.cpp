#include "position-test.hpp"

void PositionTest::setUp()
{
	position = new Position( 11, 2 );
}

void PositionTest::tearDown()
{
	delete position;
}

void PositionTest::should_check_position_x()
{
	CPPUNIT_ASSERT( position->getX() == 11 );
}

void PositionTest::should_check_position_y()
{
	CPPUNIT_ASSERT( position->getY() == 2 );
}
