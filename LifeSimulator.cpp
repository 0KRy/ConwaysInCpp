#include "LifeSimulator.hpp"
#include "Pattern.hpp"
#include <array>
#include <cstdint>
#include <iostream>
#include <thread>
#include <vector>

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) {
  m_sizeX = sizeX;
  m_sizeY = sizeY;

  // bool[sizeY][sizeY] x = {};
  std::vector<std::vector<bool>> v = {};
  for (std::uint8_t y = 0; y < sizeY; y++) {
    std::vector<bool> t = {};
    for (std::uint8_t x = 0; x < sizeX; x++) {
      t.push_back(false);
    }
    v.push_back(t);
  }

  m_grid = v;
};

void LifeSimulator::insertPattern(const Pattern &pattern, std::uint8_t startX,
                                  std::uint8_t startY) {
  for (std::uint8_t y = 0; y < pattern.getSizeY(); y++) {
    for (std::uint8_t x = 0; x < pattern.getSizeX(); x++) {
      if (((y + startY) < m_sizeY) && ((x + startX) < m_sizeX)) {
        m_grid[y + startY][x + startX] = pattern.getCell(x, y);
      }
    }
  }
};

void LifeSimulator::update() {

  std::vector<std::vector<bool>> preGrid = {};
  for (std::uint8_t y = 0; y < m_sizeY; y++) {
    std::vector<bool> t = {};
    for (std::uint8_t x = 0; x < m_sizeX; x++) {
      t.push_back(false);
    }
    preGrid.push_back(t);
  }

  for (std::uint8_t y = 0; y < m_sizeY; y++) {
    for (std::uint8_t x = 0; x < m_sizeX; x++) {
      if ((y < m_sizeY) && (x < m_sizeX)) {
        preGrid[y][x] = checkCell(x, y);
      }
    }
  }

  m_grid = preGrid;
};

bool LifeSimulator::checkCell(std::uint8_t x, std::uint8_t y) {
  std::uint8_t population = 0;

  std::uint8_t adjy = 0;
  std::uint8_t adjx = 0;
  if (y == 0) {
    adjy = 1;
  }
  if (x == 0) {
    adjx = 1;
  }

  std::uint8_t adjyE = 0;
  std::uint8_t adjxE = 0;
  if (y == m_sizeY) {
    adjy = 1;
  }
  if (x == m_sizeX) {
    adjx = 1;
  }

  for (std::uint8_t relative_y = y - 1 + adjy; relative_y <= y + 1 - adjyE;
       relative_y++) {
    for (std::uint8_t relative_x = x - 1 + adjx; relative_x <= x + 1 - adjxE;
         relative_x++) {
      if (getCell(relative_x, relative_y)) {
        population++;
      }
    }
  }
  if (getCell(x, y)) {
    if (population == 3 || population == 4) {
      return true;
    } // under/over population
  } else {
    if (population == 3) {
      return true;
    } // reproduction
  }
  return false;
};
