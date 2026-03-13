#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

class Keyboard
{
  int key;

public:
  explicit Keyboard ();
  explicit Keyboard (const Keyboard &keyboard);
  virtual ~Keyboard ();
  virtual void execute ();
  virtual auto getKey () const -> int;
  virtual auto isExit () const -> bool;
};

#endif // KEYBOARD_HPP_
