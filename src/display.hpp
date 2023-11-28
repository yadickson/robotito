#pragma once

#include <ncurses.h>

class Display
{
private:
  WINDOW *mainWindow;
  WINDOW *childWindow;

public:
  explicit Display ();
  virtual ~Display ();

  virtual void initialize ();
  virtual void reload ();

  virtual WINDOW *getWindow () const;

  virtual int getWidth () const;
  virtual int getHeight () const;

protected:
  virtual void destroy ();
};
