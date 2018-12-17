#pragma once

namespace TSP {

using tsp_float = long double;
using tsp_byte = unsigned char;
using tsp_int = long long;
using tsp_id = unsigned int;

struct tsp_position {
  tsp_float x;
  tsp_float y;
};

struct tsp_rotation {
  tsp_float rotation;
};

struct tsp_vehicle_position : tsp_position, tsp_rotation {
  tsp_id id;
};

struct tsp_vehicle_base {
  tsp_float width;
  tsp_float height;
  tsp_float frontAxle;
  tsp_float rearAxle;
  tsp_float velocity;
};

struct tsp_vehicle : tsp_vehicle_position, tsp_vehicle_base {};

} // namespace TSP
