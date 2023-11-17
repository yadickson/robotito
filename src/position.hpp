#pragma once

class Position
{
private:
  int x;
  int y;

public:
  explicit Position (const int x, const int y);
  void operator= (const Position &position);
  ~Position ();
  int getX ();
  int getY ();
  void setX (const int x);
  void setY (const int y);
};
