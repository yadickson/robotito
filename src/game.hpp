#ifndef GAME_HPP_
#define GAME_HPP_

#include "display.hpp"
#include "keyboard.hpp"
#include "robot.hpp"
#include "table.hpp"

class Game
{
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

#endif // GAME_HPP_
