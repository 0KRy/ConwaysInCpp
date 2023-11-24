#pragma once
#include "Pattern.hpp"
#include <vector>

class PatternPulsar : public Pattern {
public:
  PatternPulsar();
  virtual std::uint8_t getSizeX() const { return 13; }
  virtual std::uint8_t getSizeY() const { return 13; }
  virtual bool getCell(std::uint8_t x, std::uint8_t y) const override {
    return m_array[y][x];
  }

private:
  std::vector<std::vector<bool>> m_array;
};
