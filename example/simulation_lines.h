#ifndef SIMULATION_LINES_H
#define SIMULATION_LINES_H

#include "tslib/types.h"

static constexpr TSP::tsp_obstacle_line lines[]{
    {TSP::tsp_obstacle_type::solid, {{10.0, 3.5}, {30.0, 3.5}}},
    {TSP::tsp_obstacle_type::solid, {{30.0, 3.5}, {40.0, 4.0}}},
    {TSP::tsp_obstacle_type::solid, {{10.0, 6.5}, {30.0, 6.5}}},
    {TSP::tsp_obstacle_type::solid, {{30.0, 6.5}, {40.0, 7.0}}}};

static constexpr size_t linesCount =
    sizeof(lines) / sizeof(TSP::tsp_obstacle_line);

#endif // SIMULATION_LINES_H
