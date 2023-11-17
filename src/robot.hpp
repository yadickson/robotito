#pragma once

#include "position.hpp"

class Robot
{
private:
  Position *position;

public:
  explicit Robot (Position *position);
  Robot *operator= (const Robot *robot);
  ~Robot ();
  Position *getPosition ();
  void moveToLeft ();
  void moveToRight ();
  void moveToUp ();
  void moveToDown ();
};
