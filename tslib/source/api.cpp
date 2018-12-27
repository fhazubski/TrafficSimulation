#include "tslib/types.h"
#include "source/globals.h"
#include "source/helpers/helper_id.h"
#include "source/helpers/helper_math.h"
#include <iostream>

void foo() {}

TSP::tsp_vehicle *tspReserveMemory(TSP::tsp_int vehiclesCount) {
  return simulation.reserveMemory(vehiclesCount);
}

bool tspAddVehicle(TSP::tsp_float x, TSP::tsp_float y, TSP::tsp_float width,
                   TSP::tsp_float height, TSP::tsp_float axleDistance,
                   TSP::tsp_float frontWheelsDistance, TSP::tsp_float rotation,
                   TSP::tsp_float velocity) {
  if (!HelperMath::inRange<tsp_float>(axleDistance, 0.0, height) &&
      axleDistance != 0.0) {
    std::cerr << "Axle value is less than or equal zero or greater than height"
              << std::endl;
    return false;
  }

  return simulation.addVehicle(x, y, width, height, axleDistance,
                               frontWheelsDistance, rotation, velocity);
}

bool tspSetTime(TSP::tsp_float time) { return simulation.setTime(time); }

TSP::tsp_vehicle_position *tspGetPositions() { return nullptr; }
