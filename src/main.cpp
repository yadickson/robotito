#include <ncurses.h>

#include <clocale>
#include <iostream>

int
main (int argc, char *argv[])
{
  setlocale (LC_ALL, "");

  initscr ();
  noecho ();
  cbreak ();
  refresh ();

  WINDOW *window = newwin (0, 0, 0, 0);

  box (window, 0, 0);
  mvwaddstr (window, 1, 1, "\U0001F600");
  wrefresh (window);

  getch ();
  endwin ();

  return 0;
}
