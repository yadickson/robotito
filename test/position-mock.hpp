#pragma once

#include "macros-test.hpp"
#include "position.hpp"

#define POSITION_MOCK_GET_X_FUNCTION "getX"
#define POSITION_MOCK_SET_X_FUNCTION "setX"
#define POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X "x"
#define POSITION_MOCK_GET_Y_FUNCTION "getY"
#define POSITION_MOCK_SET_Y_FUNCTION "setY"
#define POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y "y"

class PositionMock : public Position
{
public:
  PositionMock () : Position (0, 0) {}
  virtual ~PositionMock () {}
  virtual int
  getX () const
  {
    return mock ()
        .actualCall (POSITION_MOCK_GET_X_FUNCTION)
        .onObject (this)
        .returnIntValue ();
  }
  virtual void
  setX (const int x)
  {
    mock ()
        .actualCall (POSITION_MOCK_SET_X_FUNCTION)
        .onObject (this)
        .withIntParameter (POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X, x);
  }
  virtual int
  getY () const
  {
    return mock ()
        .actualCall (POSITION_MOCK_GET_Y_FUNCTION)
        .onObject (this)
        .returnIntValue ();
  }
  virtual void
  setY (const int y)
  {
    mock ()
        .actualCall (POSITION_MOCK_SET_Y_FUNCTION)
        .onObject (this)
        .withParameter (POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y, y);
  }
};
