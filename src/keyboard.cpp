#include <cctype>
#include <ncurses.h>

#include "keyboard.hpp"

Keyboard::Keyboard () : key (0) {}

Keyboard::Keyboard (const Keyboard &keyboard) : key (keyboard.getKey ()) {}

Keyboard::~Keyboard () = default;

void
Keyboard::execute ()
{
  this->key = getch ();
}

auto
Keyboard::getKey () const -> int
{
  return this->key;
}

auto
Keyboard::isExit () const -> bool
{
  return toupper (this->key) == 'Q';
}
