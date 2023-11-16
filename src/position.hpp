#pragma once

class Position
{
private:
  int x;
  int y;

public:
  Position (int x, int y);
  ~Position ();
  int getX ();
  int getY ();
};
