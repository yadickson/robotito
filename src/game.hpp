#pragma once

#include "display.hpp"
#include "keyboard.hpp"
#include "robot.hpp"
#include "table.hpp"

class Game
{
private:
  Display *display;
  Keyboard *keyboard;
  Table *table;
  Robot *robot;

public:
  explicit Game (Display *display, Keyboard *keyboard, Table *table,
                 Robot *robot);
  explicit Game (const Game &game);
  virtual ~Game ();
  virtual void execute ();
};
