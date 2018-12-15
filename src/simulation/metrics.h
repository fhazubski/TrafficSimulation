#pragma once

#include "simulation/types.h"
#include <limits>

namespace TSP {

// editable variables
constexpr tsp_int meter = 1000;
constexpr tsp_int milisecond = 1;

constexpr tsp_int requiredLength = 10 * kilometer;
constexpr tsp_int requiredTimespan = 1 * day;

// other variables, dependending on editables
constexpr tsp_int kilometer = 1000 * meter;

constexpr tsp_int second = 1000 * milisecond;
constexpr tsp_int minute = 60 * second;
constexpr tsp_int hour = 60 * minute;
constexpr tsp_int day = 24 * hour;

constexpr tsp_int maxLength = std::numeric_limits<tsp_int>::max();
constexpr tsp_int maxTime = std::numeric_limits<tsp_int>::max();

// ensure that simulation will support required constraints
static_assert(maxLength > requiredLength);
static_assert(maxTime > requiredTimespan);

} // namespace TSP
