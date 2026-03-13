#include "position-mock.hpp"
#include "macros-test.hpp"
#include "position.hpp"

class PositionMock : public Position
{
public:
  PositionMock () : Position (0, 0) {}
  ~PositionMock () override = default;
  [[nodiscard]] auto
  getX () const -> int override
  {
    return mock ()
        .actualCall (POSITION_MOCK_GET_X_FUNCTION)
        .onObject (this)
        .returnIntValue ();
  }
  void
  setX (const int x) override
  {
    mock ()
        .actualCall (POSITION_MOCK_SET_X_FUNCTION)
        .onObject (this)
        .withIntParameter (POSITION_MOCK_SET_X_FUNCTION_PARAMETER_X, x);
  }
  [[nodiscard]] auto
  getY () const -> int override
  {
    return mock ()
        .actualCall (POSITION_MOCK_GET_Y_FUNCTION)
        .onObject (this)
        .returnIntValue ();
  }
  void
  setY (const int y) override
  {
    mock ()
        .actualCall (POSITION_MOCK_SET_Y_FUNCTION)
        .onObject (this)
        .withParameter (POSITION_MOCK_SET_Y_FUNCTION_PARAMETER_Y, y);
  }
};
