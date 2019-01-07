#include "source/globals.h"
#include "source/helpers/helper_id.h"
#include "source/helpers/helper_math.h"
#include "tslib/types.h"
#include <iostream>

TSP::tsp_vehicle *tspReserveVehicleMemory(TSP::tsp_int vehiclesCount) {
  return simulation.reserveVehicleMemory(vehiclesCount);
}

TSP::tsp_obstacle_line *tspReserveObstacleMemory(TSP::tsp_int obstacleCount) {
  return simulation.reserveObstacleMemory(obstacleCount);
}

bool tspAddVehicle(TSP::tsp_float width, TSP::tsp_float height,
                   TSP::tsp_float axleDistance,
                   TSP::tsp_float frontWheelsDistance, TSP::tsp_float velocity,
                   const TSP::tsp_road *const startRoad, TSP::tsp_int startLane) {
  if (!HelperMath::inRange<tsp_float>(axleDistance, 0.0, height) &&
      axleDistance != 0.0) {
    std::cerr << "Axle value is less than or equal zero or greater than height"
              << std::endl;
    return false;
  }

  velocity = HelperMath::kmphToMps(velocity);

  return simulation.addVehicle(width, height, axleDistance, frontWheelsDistance,
                               velocity, startRoad, startLane);
}

void tspOverrideAxleAngle(TSP::tsp_id vehicle, TSP::tsp_float angle) {
  angle = HelperMath::degreeToRadian(angle);
  simulation.overrideAxleAngle(vehicle, angle);
}

bool tspSetTime(TSP::tsp_float time) { return simulation.setTime(time); }

TSP::tsp_vehicle_position *tspGetPositions() { return nullptr; }
