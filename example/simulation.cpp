#include "simulation.h"
#include "tslib/api.h"

Simulation::Simulation(QObject *parent) : QObject(parent) {
  m_tspVehicles = tspReserveMemory(2);
  tspAddVehicle(0.0, 0.0, 1500, 4000, 4, 1, 0.0, 1);
  tspAddVehicle(0.0, 0.0, 1500, 4000, 3000, 1400, 1.0, 50);
  m_tspVehicles[0].axleAngle = 30.0 / 180.0 * std::acos(-1);
  m_vehicles.append(new Vehicle);
  // std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  // std::cout << vehicles[1].x << " " << vehicles[1].y << std::endl;
  //  for (int i = 0; i < 100; i++) {
  //  result = tspSetTime(1000);
  // std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  //}
  // std::cout << vehicles[1].x << " " << vehicles[1].y << std::endl;
  // result = tspSetTime(1000);
  // std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  // std::cout << vehicles[1].x << " " << vehicles[1].y << std::endl;
}

QQmlListProperty<Vehicle> Simulation::vehicles() {
  return QQmlListProperty<Vehicle>(this, this->m_vehicles);
}

void Simulation::setTime(qreal time) {
  tspSetTime(time);
  m_vehicles[0]->m_x = m_tspVehicles[0].x;
  m_vehicles[0]->m_y = m_tspVehicles[0].y;
  m_vehicles[0]->m_width = m_tspVehicles[0].width;
  m_vehicles[0]->m_height = m_tspVehicles[0].height;
  m_vehicles[0]->m_rotation = m_tspVehicles[0].rotation * 180.0 / std::acos(-1);
}
