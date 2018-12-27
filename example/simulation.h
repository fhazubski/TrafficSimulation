#ifndef SIMULATION_H
#define SIMULATION_H

#include "tslib/types.h"
#include "vehicle.h"
#include <QList>
#include <QObject>
#include <QQmlListProperty>

class Simulation : public QObject {
  Q_OBJECT
  Q_PROPERTY(QQmlListProperty<Vehicle> vehicles READ vehicles)

public:
  explicit Simulation(QObject *parent = nullptr);
  QQmlListProperty<Vehicle> vehicles();

public slots:
  void setTime(qreal time);

private:
  QList<Vehicle *> m_vehicles;

  TSP::tsp_vehicle *m_tspVehicles = nullptr;
};

#endif // SIMULATION_H
