#pragma once

#include "position.hpp"

class Robot
{
private:
  Position *position;

public:
  Robot (int x, int y);
  Robot (Position *position);
  Position *getPosition ();
  void moveLeft ();
  void moveRight ();
  void moveUp ();
  void moveDown ();
};
