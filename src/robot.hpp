#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "position.hpp"

class Robot
{
  Position *position;

public:
  explicit Robot (Position *position);
  explicit Robot (const Robot &robot);
  virtual ~Robot ();
  auto operator= (const Robot &robot) -> Robot &;
  virtual auto getPosition () const -> Position *;
  virtual void moveToLeft ();
  virtual void moveToRight ();
  virtual void moveToUp ();
  virtual void moveToDown ();
};

#endif // ROBOT_HPP_
