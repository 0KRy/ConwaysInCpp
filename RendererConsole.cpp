#include "RendererConsole.hpp"
#include "LifeSimulator.hpp"
#include "Renderer.hpp"
#include "rlutil.h"

void RendererConsole::render(const LifeSimulator &simulation) {
  if (m_first) {
    rlutil::cls();
    std::vector<std::vector<bool>> v = {};
    for (std::uint8_t y = 0; y < simulation.getSizeY(); y++) {
      std::vector<bool> t = {};
      for (std::uint8_t x = 0; x < simulation.getSizeX(); x++) {
        t.push_back(false);
      }
      v.push_back(t);
    }
    m_prev = v;
    m_first = false;
  }

  rlutil::hidecursor();

  for (std::uint8_t y = 0; y < simulation.getSizeY(); y++) {
    for (std::uint8_t x = 0; x < simulation.getSizeX(); x++) {
      bool currentCell = simulation.getCell(x, y);

      if (m_prev[y][x] != currentCell) {
        rlutil::locate(x, y);
        m_prev[y][x] = currentCell;
        if (currentCell) {
          rlutil::setChar('X');
        } else {
          rlutil::setChar(' ');
        }
      }
    }
  }

  std::cout << std::flush;
}
