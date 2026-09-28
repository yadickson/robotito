#include "display.hpp"
#include "game.hpp"
#include "keyboard.hpp"
#include "position.hpp"
#include "robot.hpp"
#include "table.hpp"
#include <clocale>

auto
main () -> int
{
  setlocale (LC_ALL, "");

  Display display;
  Keyboard keyboard;
  Table table;
  Position position;
  Robot robot (&position);
  Game game (&display, &keyboard, &table, &robot);

  game.execute ();

  return 0;
}
