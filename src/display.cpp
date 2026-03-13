#include <cstddef>

#include "display.hpp"

Display::Display () : window (nullptr) {}

Display::~Display () { Display::destroy (); }

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

auto
Display::getWindow () const -> WINDOW *
{
  return window;
}

auto
Display::getWidth () const -> int
{
  return window ? getmaxx (window) : 0;
}

auto
Display::getHeight () const -> int
{
  return window ? getmaxy (window) : 0;
}

void
Display::destroy ()
{

  if (window)
    delwin (window);

  endwin ();

  window = nullptr;
}
