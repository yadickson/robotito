#include <clocale>
#include <iostream>
#include <ncurses.h>

#include "game.hpp"
#include "keyboard.hpp"
#include "position.hpp"
#include "robot.hpp"
#include "table.hpp"

int
main (int argc, char *argv[])
{
  setlocale (LC_ALL, "");

  WINDOW *mainwin = initscr ();
  start_color ();
  init_pair (1, COLOR_YELLOW, COLOR_GREEN);
  noecho ();
  cbreak ();
  keypad (mainwin, TRUE);
  curs_set (0);
  refresh ();

  WINDOW *childwin = subwin (mainwin, 0, 0, 0, 0);

  int maxX = getmaxx (childwin);
  int maxY = getmaxy (childwin);

  Keyboard keyboard;
  Table table (maxX, maxY);
  Position position (1, 1);
  Robot robot (&position, "\U0001F600");

  Game game (childwin, &keyboard, &table, &robot);

  game.execute ();

  delwin (childwin);
  delwin (mainwin);
  endwin ();
  refresh ();

  return 0;
}
