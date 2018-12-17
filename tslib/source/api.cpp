#include "include/types.h"
#include "source/helpers/helper_id.h"
#include "source/helpers/helper_math.h"
#include "source/globals.h"
#include <iostream>

void foo() {}

TSP::tsp_id tspAddVehicle(TSP::tsp_float x, TSP::tsp_float y,
                          TSP::tsp_float width, TSP::tsp_float height,
                          TSP::tsp_float frontAxle, TSP::tsp_float rearAxle,
                          TSP::tsp_float rotation, TSP::tsp_float velocity) {
  if (!HelperMath::inRange<tsp_float>(frontAxle, 0.0, 1.0) ||
      !HelperMath::inRange<tsp_float>(rearAxle, 0.0, 1.0)) {
    std::cerr << "Axle value is out of range" << std::endl;
    return 0;
  }

  tsp_vehicle vehicle;
  vehicle.id = HelperId::next();
  vehicle.x = x;
  vehicle.y = y;
  vehicle.width = width;
  vehicle.height = height;
  vehicle.frontAxle = frontAxle;
  vehicle.rearAxle = rearAxle;
  vehicle.rotation = rotation;
  vehicle.velocity = velocity;

  if (vehicle.id != 0) {
    simulation.addVehicle(vehicle);
  }

  return vehicle.id;
}

bool tspSetTime(TSP::tsp_float time) { return true; }

TSP::tsp_vehicle_position *tspGetPositions() { return nullptr; }
