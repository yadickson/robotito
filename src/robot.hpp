#pragma once

#include "position.hpp"
#include <iostream>

class Robot
{
private:
  Position *position;
  std::string image;

public:
  explicit Robot (Position *position, const char *image);
  explicit Robot (const Robot &robot);
  virtual ~Robot ();
  void operator= (const Robot &robot);
  virtual Position *getPosition () const;
  virtual const char *getImage () const;
  virtual void moveToLeft ();
  virtual void moveToRight ();
  virtual void moveToUp ();
  virtual void moveToDown ();
};
