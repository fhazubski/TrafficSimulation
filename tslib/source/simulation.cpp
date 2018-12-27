#include "source/simulation.h"
#include "source/helpers/helper_math.h"

namespace TSP {

tsp_vehicle *Simulation::reserveMemory(tsp_int count) {
  if (vehicles != nullptr) {
    delete[] vehicles;
  }
  vehicles = new tsp_vehicle[count];
  reservedVehiclesCount = count;
  vehiclesCount = 0;
  nextFree = 0;
  return vehicles;
}

bool Simulation::addVehicle(tsp_float x, tsp_float y, tsp_float width,
                            tsp_float height, tsp_float axleDistance,
                            tsp_float frontWheelsDistance, tsp_float rotation,
                            tsp_float velocity) {
  if (nextFree >= reservedVehiclesCount) {
    return false;
  }

  vehicles[nextFree].id = nextFree;
  vehicles[nextFree].x = x;
  vehicles[nextFree].y = y;
  vehicles[nextFree].width = width;
  vehicles[nextFree].height = height;
  vehicles[nextFree].axleAngle = 0.0;
  vehicles[nextFree].frontWheelsDistance = frontWheelsDistance;
  vehicles[nextFree].axleDistance = axleDistance;
  vehicles[nextFree].rotation = rotation;
  vehicles[nextFree].velocity = velocity;
  nextFree++;
  vehiclesCount = nextFree;

  return true;
}

bool Simulation::setTime(tsp_float newTime) {
  if (newTime <= time) {
    return false;
  }

  tsp_float timeDifference = newTime - time;
  for (tsp_int i = 0; i < vehiclesCount; i++) {
    HelperMath::updatePosition(vehicles[i], 0.0, 0.0, timeDifference);
  }
  return true;
}

} // namespace TSP
