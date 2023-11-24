#pragma once
#include "Pattern.hpp"
#include <vector>

class PatternGosperGliderGun : public Pattern {
public:
  PatternGosperGliderGun();
  virtual std::uint8_t getSizeX() const { return 36; }
  virtual std::uint8_t getSizeY() const { return 9; }
  virtual bool getCell(std::uint8_t x, std::uint8_t y) const override {
    return m_array[y][x];
  }

private:
  std::vector<std::vector<bool>> m_array;
};
