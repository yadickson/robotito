#pragma once

class Position
{
private:
  int x;
  int y;

public:
  explicit Position (const Position &position);
  explicit Position (const int x, const int y);
  virtual ~Position ();
  void operator= (const Position &position);
  virtual int getX () const;
  virtual int getY () const;
  virtual void setX (const int x);
  virtual void setY (const int y);
};
