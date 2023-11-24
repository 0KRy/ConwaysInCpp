#pragma once

#include "Pattern.hpp"
#include <cstdint>
#include <vector>

class LifeSimulator {
public:
  LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);

  void insertPattern(const Pattern &pattern, std::uint8_t startX,
                     std::uint8_t startY);

  void update();

  std::uint8_t getSizeX() const { return m_sizeX; }
  std::uint8_t getSizeY() const { return m_sizeY; }
  bool getCell(std::uint8_t x, std::uint8_t y) const {
    if ((x >= m_sizeX) || (y >= m_sizeY)) {
      return false;
    } else {
      return m_grid[y][x];
    };
  }

private:
  std::uint8_t m_sizeX;
  std::uint8_t m_sizeY;
  std::vector<std::vector<bool>> m_grid;

  bool checkCell(std::uint8_t x, std::uint8_t y);
};
