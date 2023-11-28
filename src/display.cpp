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
  keypad (mainWindow, TRUE);
  curs_set (0);
  refresh ();

  childWindow = subwin (mainWindow, 0, 0, 0, 0);

  box (childWindow, 0, 0);
}

void
Display::reload ()
{
  destroy ();
  initialize ();
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
