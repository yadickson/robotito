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

  robot->getPosition ()->setX (COLS / 2);
  robot->getPosition ()->setY (LINES / 2);

  wchar_t emoji[] = L"\U0001F916";

  do
    {

      int x = robot->getPosition ()->getX () < COLS - 3
                  ? robot->getPosition ()->getX ()
                  : COLS - 3;
      int y = robot->getPosition ()->getY () < LINES - 2
                  ? robot->getPosition ()->getY ()
                  : LINES - 2;

      robot->getPosition ()->setX (x);
      robot->getPosition ()->setY (y);

      mvwaddwstr (display->getWindow (), y, x, emoji);

      wrefresh (display->getWindow ());

      keyboard->execute ();

      mvwaddch (display->getWindow (), y, x, ' ');

      const int key = keyboard->getKey ();

      switch (key)
        {
        case KEY_RESIZE:
          display->reload ();
          break;
        case 260:
          if (this->table->canMoveToLeft (*robot))
            this->robot->moveToLeft ();
          break;
        case 261:
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
