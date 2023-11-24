#include "PatternAcorn.hpp"
#include "Pattern.hpp"
#include <vector>

PatternAcorn::PatternAcorn() {
  m_array = {{false, true, false, false, false, false, false},
             {false, false, false, true, false, false, false},
             {true, true, false, false, true, true, true}};
};
