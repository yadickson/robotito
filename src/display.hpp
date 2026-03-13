#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <ncurses.h>

class Display
{
  WINDOW *window;

public:
  explicit Display ();
  virtual ~Display ();

  virtual void initialize ();
  virtual void reload ();

  virtual auto getWindow () const -> WINDOW *;

  virtual auto getWidth () const -> int;
  virtual auto getHeight () const -> int;

protected:
  virtual void destroy ();
};

#endif // DISPLAY_HPP_
