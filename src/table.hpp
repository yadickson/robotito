#ifndef TABLE_HPP_
#define TABLE_HPP_

#include "robot.hpp"

class Table
{
public:
  virtual ~Table ();

  [[nodiscard]] virtual auto canMoveToLeft (const Robot &robot) const -> bool;
  [[nodiscard]] virtual auto canMoveToRight (const Robot &robot) const -> bool;
  [[nodiscard]] virtual auto canMoveToUp (const Robot &robot) const -> bool;
  [[nodiscard]] virtual auto canMoveToDown (const Robot &robot) const -> bool;
};

#endif // TABLE_HPP_
