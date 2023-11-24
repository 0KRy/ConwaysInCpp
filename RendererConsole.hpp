#pragma once

#include "LifeSimulator.hpp"
#include "Renderer.hpp"

class RendererConsole : public Renderer {
public:
  void render(const LifeSimulator &simulation);

private:
  bool m_first = true;
  std::vector<std::vector<bool>> m_prev;
};
