#include "PatternPulsar.hpp"
#include "Pattern.hpp"
#include <vector>

PatternPulsar::PatternPulsar() {
  m_array = {{false, false, true, true, true, false, false, false, true, true,
              true, false, false},
             {false, false, false, false, false, false, false, false, false,
              false, false, false, false},
             {true, false, false, false, false, true, false, true, false, false,
              false, false, true},
             {true, false, false, false, false, true, false, true, false, false,
              false, false, true},
             {true, false, false, false, false, true, false, true, false, false,
              false, false, true},
             {false, false, true, true, true, false, false, false, true, true,
              true, false, false},
             {false, false, false, false, false, false, false, false, false,
              false, false, false, false},
             {false, false, true, true, true, false, false, false, true, true,
              true, false, false},
             {true, false, false, false, false, true, false, true, false, false,
              false, false, true},
             {true, false, false, false, false, true, false, true, false, false,
              false, false, true},
             {true, false, false, false, false, true, false, true, false, false,
              false, false, true},
             {false, false, false, false, false, false, false, false, false,
              false, false, false, false},
             {false, false, true, true, true, false, false, false, true, true,
              true, false, false}};
};
