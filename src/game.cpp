#include <ncurses.h>

#include "game.hpp"

Game::Game (WINDOW *window, Keyboard *keyboard, Table *table, Robot *robot)
{
  this->window = window;
  this->keyboard = keyboard;
  this->table = table;
  this->robot = robot;
}

Game::Game (const Game &game)
{
  this->window = game.window;
  this->keyboard = game.keyboard;
  this->table = game.table;
  this->robot = game.robot;
}

Game::~Game () {}

void
Game::execute ()
{
  box (window, 0, 0);

  do
    {

      mvwaddstr (window, robot->getPosition ()->getY (),
                 robot->getPosition ()->getX (), robot->getImage ());

      wrefresh (window);

      keyboard->execute ();

      mvwaddstr (window, robot->getPosition ()->getY (),
                 robot->getPosition ()->getX (), " ");

      const int key = keyboard->getKey ();

      switch (key)
        {
        case 261:
          this->robot->moveToLeft ();
          break;
        case 260:
          this->robot->moveToRight ();
          break;
        case 259:
          this->robot->moveToUp ();
          break;
        case 258:
          this->robot->moveToDown ();
          break;
        }
    }
  while (!keyboard->isExit ());
}
