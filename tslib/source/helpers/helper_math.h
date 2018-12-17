#pragma once
#include "source/base.h"
#include <functional>

using namespace TSP;

namespace TSP {

class HelperMath {
public:
  template <typename T> static bool inRange(T value, T smaller, T bigger) {
    return !std::less<T>()(value, smaller) && !std::less<T>()(bigger, value);
  }
};

} // namespace TSP
