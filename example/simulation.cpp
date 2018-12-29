#include "simulation.h"
#include "tslib/api.h"

Simulation::Simulation(QObject *parent) : QObject(parent) {
  m_tspVehicles = tspReserveMemory(10);
}

QQmlListProperty<Vehicle> Simulation::vehicles() {
  return QQmlListProperty<Vehicle>(this, this->m_vehicles);
}

void Simulation::setTime(qreal time) {
  tspSetTime(time);
  for (int i = 0; i < m_vehicles.count(); i++) {
    m_vehicles[i]->setX(m_tspVehicles[i].x);
    m_vehicles[i]->setY(m_tspVehicles[i].y);
    m_vehicles[i]->setWidth(m_tspVehicles[i].width);
    m_vehicles[i]->setHeight(m_tspVehicles[i].height);
    m_vehicles[i]->setRotation(m_tspVehicles[i].rotation * 180.0 /
                               std::acos(-1));
  }
}

void Simulation::addVehicle(qreal x, qreal y, qreal width, qreal height,
                            qreal rotation, qreal velocity) {
  tspAddVehicle(x, y, width, height, height * 0.85, width * 0.95, rotation,
                velocity);
  m_vehicles.append(new Vehicle);
  emit vehiclesChanged();
}

void Simulation::overrideAxleAngle(quint8 vehicle, qreal angle) {
  tspOverrideAxleAngle(vehicle, angle);
}
