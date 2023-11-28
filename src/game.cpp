#include <ncurses.h>

#include "game.hpp"

Game::Game (Display *display, Keyboard *keyboard, Table *table, Robot *robot)
{
  this->display = display;
  this->keyboard = keyboard;
  this->table = table;
  this->robot = robot;
}

Game::Game (const Game &game)
{
  this->display = game.display;
  this->keyboard = game.keyboard;
  this->table = game.table;
  this->robot = game.robot;
}

Game::~Game () {}

void
Game::execute ()
{
  display->initialize ();

  do
    {

      mvwaddch (display->getWindow (), robot->getPosition ()->getY (),
                robot->getPosition ()->getX (), '*');

      wrefresh (display->getWindow ());

      keyboard->execute ();

      mvwaddch (display->getWindow (), robot->getPosition ()->getY (),
                robot->getPosition ()->getX (), ' ');

      const int key = keyboard->getKey ();

      switch (key)
        {
        case 261:
          if (this->table->canMoveToLeft (*robot))
            this->robot->moveToLeft ();
          break;
        case 260:
          if (this->table->canMoveToRight (*robot))
            this->robot->moveToRight ();
          break;
        case 259:
          if (this->table->canMoveToUp (*robot))
            this->robot->moveToUp ();
          break;
        case 258:
          if (this->table->canMoveToDown (*robot))
            this->robot->moveToDown ();
          break;
        }
    }
  while (!keyboard->isExit ());
}
