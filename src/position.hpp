#ifndef POSITION_HPP_
#define POSITION_HPP_

class Position
{
  int x;
  int y;

public:
  explicit Position ();
  explicit Position (const Position &position);
  explicit Position (int x, int y);
  virtual ~Position ();
  auto operator= (const Position &position) -> Position &;
  [[nodiscard]] virtual auto getX () const -> int;
  [[nodiscard]] virtual auto getY () const -> int;
  virtual void setX (int x);
  virtual void setY (int y);
};

#endif // POSITION_HPP_