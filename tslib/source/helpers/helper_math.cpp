#include "source/helpers/helper_math.h"
#include <iostream>
#include <cmath>

#define PI                                                                     \
  (3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442)

namespace TSP {

tsp_float HelperMath::turnRadius(const tsp_float axleDistance,
                                 const tsp_float axleAngle) {
  return std::tan(tsp_float(90.0) - axleAngle) * axleDistance;
}

void HelperMath::updatePosition(tsp_vehicle &vehicle,
                                const tsp_float velocityChange,
                                const tsp_float axleAngleChange,
                                const tsp_float timeChange) {
  tsp_float distance =
      (vehicle.velocity + velocityChange * timeChange / 2.0) * timeChange;

  if (vehicle.axleAngle == 0.0 &&
      (axleAngleChange == 0.0 || timeChange == 0.0)) {
    vehicle.x += std::cos(vehicle.rotation) * distance;
    vehicle.y += std::sin(vehicle.rotation) * distance;
    return;
  }
  tsp_float rearTiersAverageRadius =
      vehicle.axleDistance / std::tan(vehicle.axleAngle);
  tsp_float pow2AxleDistance = std::pow(vehicle.axleDistance, 2);
  tsp_float halfFrontWheelsDistance = vehicle.frontWheelsDistance / 2.0;
  // calculate the radius as an average from all of the wheels
  tsp_float radius =
      2.0 * rearTiersAverageRadius +
      std::sqrt(pow2AxleDistance +
                std::pow(rearTiersAverageRadius - halfFrontWheelsDistance, 2)) +
      std::sqrt(pow2AxleDistance +
                std::pow(rearTiersAverageRadius + halfFrontWheelsDistance, 2));
  radius /= 4.0;
  tsp_float beta = distance / radius;
  tsp_position vector = {std::sin(beta) * radius,
                         radius * (1.0 - std::cos(beta))};

  vehicle.x += std::cos(vehicle.rotation) * vector.x -
               std::sin(vehicle.rotation) * vector.y;
  vehicle.y += std::sin(vehicle.rotation) * vector.x +
               std::cos(vehicle.rotation) * vector.y;
  vehicle.rotation += beta;
}

} // namespace TSP