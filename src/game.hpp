#pragma once

#include "keyboard.hpp"
#include "robot.hpp"
#include "table.hpp"
#include <ncurses.h>

class Game
{
private:
  WINDOW *window;
  Keyboard *keyboard;
  Table *table;
  Robot *robot;

public:
  explicit Game (WINDOW *window, Keyboard *keyboard, Table *table,
                 Robot *robot);
  explicit Game (const Game &game);
  virtual ~Game ();
  virtual void execute ();
};
