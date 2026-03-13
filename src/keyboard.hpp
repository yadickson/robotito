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
  [[nodiscard]] virtual auto getKey () const -> int;
  [[nodiscard]] virtual auto isExit () const -> bool;
};

#endif // KEYBOARD_HPP_
