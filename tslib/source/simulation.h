#pragma once
#include "source/base.h"
#include <vector>

namespace TSP {

class Simulation {
public:
  tsp_vehicle *reserveMemory(tsp_int count);
  bool addVehicle(tsp_float x, tsp_float y, tsp_float width, tsp_float height,
                  tsp_float axleDistance, tsp_float frontWheelsDistance,
                  tsp_float rotation, tsp_float velocity);
  void overrideAxleAngle(TSP::tsp_id vehicle, TSP::tsp_float angle);
  bool setTime(tsp_float newTime);

private:
  tsp_vehicle *vehicles = nullptr;
  tsp_int reservedVehiclesCount;
  tsp_int vehiclesCount;
  tsp_int nextFree;
  tsp_float time = 0;
};

} // namespace TSP
