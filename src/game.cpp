#include <ncurses.h>

#include "game.hpp"

#include <array>

Game::Game (Display *display, Keyboard *keyboard, Table *table, Robot *robot)
    : display (display), keyboard (keyboard), table (table), robot (robot)
{
}

Game::Game (const Game &game)

    = default;

Game::~Game () = default;

void
Game::execute ()
{
  display->initialize ();

  robot->getPosition ()->setX (COLS / 2);
  robot->getPosition ()->setY (LINES / 2);

  const char *emoji = "\U0001F916";
  constexpr std::array<char, 2> clean = { ' ', '\0' };

  while (!keyboard->isExit ())
    {

      int x = robot->getPosition ()->getX () < COLS - 3
                  ? robot->getPosition ()->getX ()
                  : COLS - 3;
      int y = robot->getPosition ()->getY () < LINES - 2
                  ? robot->getPosition ()->getY ()
                  : LINES - 2;

      robot->getPosition ()->setX (x);
      robot->getPosition ()->setY (y);

      mvwaddstr (display->getWindow (), y, x, emoji);

      keyboard->execute ();

      mvwaddstr (display->getWindow (), y, x, clean.data ());

      const int key = keyboard->getKey ();

      switch (key)
        {
        case KEY_RESIZE:
          display->reload ();
          break;
        case KEY_LEFT:
          if (this->table->canMoveToLeft (*robot))
            this->robot->moveToLeft ();
          break;
        case KEY_RIGHT:
          if (this->table->canMoveToRight (*robot))
            this->robot->moveToRight ();
          break;
        case KEY_UP:
          if (this->table->canMoveToUp (*robot))
            this->robot->moveToUp ();
          break;
        case KEY_DOWN:
          if (this->table->canMoveToDown (*robot))
            this->robot->moveToDown ();
          break;
        }
    }
}
