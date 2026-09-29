#ifndef FAKER_CXX_HPP_
#define FAKER_CXX_HPP_

class FakerCxx
{
public:
  virtual ~FakerCxx () = default;
  [[nodiscard]] static auto getNumber (int min, int max) -> int;
};

#endif