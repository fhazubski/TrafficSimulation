#include "source/globals.h"
#include "source/helpers/helper_id.h"
#include "source/helpers/helper_math.h"
#include "tslib/types.h"
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

  rotation = HelperMath::degreeToRadian(rotation);
  velocity = HelperMath::kmphToMps(velocity);

  return simulation.addVehicle(x, y, width, height, axleDistance,
                               frontWheelsDistance, rotation, velocity);
}

void tspOverrideAxleAngle(TSP::tsp_id vehicle, TSP::tsp_float angle) {
  angle = HelperMath::degreeToRadian(angle);
  simulation.overrideAxleAngle(vehicle, angle);
}

bool tspSetTime(TSP::tsp_float time) { return simulation.setTime(time); }

TSP::tsp_vehicle_position *tspGetPositions() { return nullptr; }
