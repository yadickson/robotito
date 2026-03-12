#include <cstddef>

#include "display.hpp"

Display::Display () { this->window = NULL; }

Display::~Display () { destroy (); }

void
Display::initialize ()
{

  window = initscr ();
  noecho ();
  cbreak ();
  keypad (window, TRUE);
  curs_set (0);

  reload ();
}

void
Display::reload ()
{
  wclear (window);
  wborder (window, 0, 0, 0, 0, 0, 0, 0, 0);
}

void
Display::destroy ()
{

  if (window)
    delwin (window);

  endwin ();

  window = NULL;
}

WINDOW *
Display::getWindow () const
{
  return window;
}

int
Display::getWidth () const
{
  return window ? getmaxx (window) : 0;
}

int
Display::getHeight () const
{
  return window ? getmaxy (window) : 0;
}
