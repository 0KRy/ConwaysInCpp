#pragma once
#include "Pattern.hpp"
#include <vector>

class PatternAcorn : public Pattern {
public:
  PatternAcorn();
  std::uint8_t getSizeX() const override { return 7; }
  std::uint8_t getSizeY() const override { return 3; }
  bool getCell(std::uint8_t x, std::uint8_t y) const override {
    return m_array[y][x];
  }

private:
  std::vector<std::vector<bool>> m_array;
};
