#pragma once

#include "robot.hpp"

class Table
{
public:
  virtual ~Table ();

  virtual bool canMoveToLeft (const Robot &robot) const;
  virtual bool canMoveToRight (const Robot &robot) const;
  virtual bool canMoveToUp (const Robot &robot) const;
  virtual bool canMoveToDown (const Robot &robot) const;
};
