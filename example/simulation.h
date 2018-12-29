#ifndef SIMULATION_H
#define SIMULATION_H

#include "tslib/types.h"
#include "vehicle.h"
#include <QList>
#include <QObject>
#include <QQmlListProperty>

class Simulation : public QObject {
  Q_OBJECT
  Q_PROPERTY(
      QQmlListProperty<Vehicle> vehicles READ vehicles NOTIFY vehiclesChanged)

public:
  explicit Simulation(QObject *parent = nullptr);
  QQmlListProperty<Vehicle> vehicles();
  TSP::tsp_obstacle_line *obstacles();

public slots:
  void setTime(qreal time);
  void addVehicle(qreal x, qreal y, qreal width, qreal height, qreal rotation,
                  qreal velocity);
  void overrideAxleAngle(quint8 vehicle, qreal angle);

signals:
  void vehiclesChanged();

private:
  QList<Vehicle *> m_vehicles;

  TSP::tsp_vehicle *m_tspVehicles = nullptr;
  TSP::tsp_obstacle_line *m_tspObstacles = nullptr;
};

#endif // SIMULATION_H
