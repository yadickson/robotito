#include <cstddef>

#include "display.hpp"

Display::Display ()
{
  this->mainWindow = NULL;
  this->childWindow = NULL;
}

Display::~Display () { destroy (); }

void
Display::initialize ()
{

  mainWindow = initscr ();
  noecho ();
  cbreak ();
  keypad (stdscr, TRUE);
  curs_set (0);

  childWindow = subwin (mainWindow, 0, 0, 0, 0);

  reload ();
}

void
Display::reload ()
{
  clear ();
  box (childWindow, 0, 0);
  refresh ();
}

void
Display::destroy ()
{

  if (childWindow)
    delwin (childWindow);

  if (mainWindow)
    delwin (mainWindow);

  endwin ();

  childWindow = NULL;
  mainWindow = NULL;
}

WINDOW *
Display::getWindow () const
{
  return childWindow;
}

int
Display::getWidth () const
{
  return childWindow ? getmaxx (childWindow) : 0;
}

int
Display::getHeight () const
{
  return childWindow ? getmaxy (childWindow) : 0;
}
