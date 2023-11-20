#pragma once

#include "robot.hpp"

class Table
{
private:
  int width;
  int height;

public:
  explicit Table (const Table &table);
  explicit Table (const int width, const int height);
  virtual ~Table ();
  void operator= (const Table &table);
  virtual int getWidth () const;
  virtual int getHeight () const;

  virtual bool canMoveToLeft (const Robot &robot) const;
  virtual bool canMoveToRight (const Robot &robot) const;
  virtual bool canMoveToUp (const Robot &robot) const;
  virtual bool canMoveToDown (const Robot &robot) const;
};
