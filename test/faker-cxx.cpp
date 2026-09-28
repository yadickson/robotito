#include "faker-cxx.hpp"

#include <cstdlib>

auto
FakerCxx::getNumber (const int min, const int max) -> int
{
  return min + (max * rand () % 100);
}
