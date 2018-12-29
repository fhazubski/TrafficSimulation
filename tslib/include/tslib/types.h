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

struct tsp_line {
  tsp_position start;
  tsp_position end;
};

enum class tsp_obstacle_type {
  solid,
  road_line,
};

struct tsp_obstacle_line {
  tsp_obstacle_type type;
  tsp_line line;
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
  tsp_float axleDistance;
  tsp_float frontWheelsDistance;
  tsp_float velocity;
  tsp_float axleAngle;
};

struct tsp_engine {
  tsp_float desiredVelocity;
  tsp_float force;
};

struct tsp_steeringAxle {
  tsp_float desiredAxleAngle;
};

struct tsp_vehicle : tsp_vehicle_position, tsp_vehicle_base {};

} // namespace TSP
