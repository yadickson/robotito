#pragma once

#include <ncurses.h>

#include "display.hpp"
#include "robot.hpp"

class Table
{
private:
  Display *display;

public:
  explicit Table (Display *display);
  explicit Table (const Table &table);
  virtual ~Table ();
  void operator= (const Table &table);

  virtual bool canMoveToLeft (const Robot &robot) const;
  virtual bool canMoveToRight (const Robot &robot) const;
  virtual bool canMoveToUp (const Robot &robot) const;
  virtual bool canMoveToDown (const Robot &robot) const;
};
