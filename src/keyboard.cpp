#include <ctype.h>
#include <ncurses.h>

#import "keyboard.hpp"

Keyboard::Keyboard () { this->key = 0; }

Keyboard::Keyboard (const Keyboard &keyboard)
{
  this->key = keyboard.getKey ();
}

Keyboard::~Keyboard () {}

void
Keyboard::execute ()
{
  this->key = getch ();
}

int
Keyboard::getKey () const
{
  return this->key;
}

bool
Keyboard::isExit () const
{
  return toupper (this->key) == 'Q';
}
