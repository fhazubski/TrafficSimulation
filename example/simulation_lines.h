#ifndef SIMULATION_LINES_H
#define SIMULATION_LINES_H

#include "tslib/types.h"

static constexpr TSP::tsp_position road1lane1points[] = {
    {0.0, 0.0},   {50.0, 0.0},  {53.0, 1.0},
    {62.0, 10.0}, {65.0, 11.0}, {100.0, 11.0}};
static constexpr TSP::tsp_position road1lane2points[] = {
    {0.0, 3.0},   {48.0, 3.0},  {51.0, 4.0},
    {60.0, 13.0}, {63.0, 14.0}, {100.0, 14.0}};
static constexpr TSP::tsp_position road1lane3points[] = {
    {0.0, 6.0},   {46.0, 6.0},  {49.0, 7.0},
    {58.0, 16.0}, {61.0, 17.0}, {100.0, 17.0}};

static constexpr TSP::tsp_road_lane road1lane1 = {6, road1lane1points};
static constexpr TSP::tsp_road_lane road1lane2 = {6, road1lane2points};
static constexpr TSP::tsp_road_lane road1lane3 = {6, road1lane3points};

static constexpr const TSP::tsp_road_lane *road1Lanes[] = {
    &road1lane1, &road1lane2, &road1lane3};

static constexpr TSP::tsp_road road1 = {3, road1Lanes};

static constexpr const TSP::tsp_road *roads[] = {&road1};

static constexpr TSP::tsp_obstacle_line lines[]{
    {TSP::tsp_obstacle_type::solid, {{10.0, 3.5}, {30.0, 3.5}}},
    {TSP::tsp_obstacle_type::solid, {{30.0, 3.5}, {40.0, 4.0}}},
    {TSP::tsp_obstacle_type::solid, {{10.0, 6.5}, {30.0, 6.5}}},
    {TSP::tsp_obstacle_type::solid, {{30.0, 6.5}, {40.0, 7.0}}}};

static constexpr size_t linesCount =
    sizeof(lines) / sizeof(TSP::tsp_obstacle_line);

#endif // SIMULATION_LINES_H
