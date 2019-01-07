#include "source/simulation.h"
#include "source/helpers/helper_math.h"

namespace TSP {

tsp_vehicle *Simulation::reserveVehicleMemory(tsp_int count) {
  if (vehicles != nullptr) {
    delete[] vehicles;
  }
  vehicles = new tsp_vehicle[count];
  reservedVehiclesCount = count;
  vehiclesCount = 0;
  nextFree = 0;
  return vehicles;
}

tsp_obstacle_line *Simulation::reserveObstacleMemory(tsp_int count) {
  if (obstacles != nullptr) {
    delete[] obstacles;
  }
  obstacles = new tsp_obstacle_line[count];
  obstacleLinesCount = count;
  return obstacles;
}

bool Simulation::addVehicle(tsp_float width, tsp_float height,
                            tsp_float axleDistance,
                            tsp_float frontWheelsDistance, tsp_float velocity,
                            const tsp_road *const startRoad,
                            tsp_int startLane) {
  if (nextFree >= reservedVehiclesCount) {
    return false;
  }
  vehicles[nextFree] = tsp_vehicle(startRoad);
  vehicles[nextFree].id = nextFree;
  vehicles[nextFree].width = width;
  vehicles[nextFree].height = height;
  vehicles[nextFree].axleAngle = 0.0;
  vehicles[nextFree].frontWheelsDistance = frontWheelsDistance;
  vehicles[nextFree].axleDistance = axleDistance;
  vehicles[nextFree].velocity = velocity;
  vehicles[nextFree].followedLane = startLane;
  vehicles[nextFree].x = startRoad->lanes[startLane]->points[0].x;
  vehicles[nextFree].y = startRoad->lanes[startLane]->points[0].y;
  vehicles[nextFree].rotation = HelperMath::lineToRotation(startRoad->lanes[startLane]->points);
  nextFree++;
  vehiclesCount = nextFree;

  return true;
}

void Simulation::overrideAxleAngle(TSP::tsp_id vehicle, TSP::tsp_float angle) {
  vehicles[vehicle].axleAngle = angle;
}

bool Simulation::setTime(tsp_float newTime) {
  if (newTime <= time) {
    return false;
  }

  tsp_float timeDifference = (newTime - time) / 1000.0;
  for (tsp_int i = 0; i < vehiclesCount; i++) {
    HelperMath::updatePosition(vehicles[i], 0.0, 0.0, timeDifference);
  }
  time = newTime;
  return true;
}

} // namespace TSP
