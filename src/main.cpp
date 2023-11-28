#include <clocale>
#include <iostream>
#include <ncurses.h>

#include "display.hpp"
#include "game.hpp"
#include "keyboard.hpp"
#include "position.hpp"
#include "robot.hpp"
#include "table.hpp"

int
main (int argc, char *argv[])
{
  setlocale (LC_ALL, "");

  Display display;
  Keyboard keyboard;
  Table table (&display);
  Position position (2, 1);
  Robot robot (&position);
  Game game (&display, &keyboard, &table, &robot);

  game.execute ();

  return 0;
}
