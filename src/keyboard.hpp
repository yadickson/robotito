#pragma once

class Keyboard
{
private:
  int key;

public:
  explicit Keyboard ();
  explicit Keyboard (const Keyboard &keyboard);
  virtual ~Keyboard ();
  virtual void execute ();
  virtual int getKey () const;
  virtual bool isExit () const;
};
