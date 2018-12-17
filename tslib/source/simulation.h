#pragma once
#include "source/base.h"
#include <vector>

namespace TSP {

class Simulation {
public:
  void addVehicle(tsp_vehicle &vehicle);

private:
  std::vector<tsp_vehicle> vehicles;
};

} // namespace TSP
