#pragma once

#include "position.hpp"

class Robot
{
private:
  Position *position;

public:
  explicit Robot (Position *position);
  explicit Robot (const Robot &robot);
  virtual ~Robot ();
  void operator= (const Robot &robot);
  virtual Position *getPosition () const;
  virtual void moveToLeft ();
  virtual void moveToRight ();
  virtual void moveToUp ();
  virtual void moveToDown ();
};
