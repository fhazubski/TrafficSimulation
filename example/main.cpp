#include "tslib/api.h"
#include "tslib/types.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  TSP::tsp_vehicle *vehicles = tspReserveMemory(100);
  bool result = tspAddVehicle(0.0, 0.0, 1500, 4000, 4000, 0.0, 50);
  result = tspAddVehicle(0.0, 0.0, 1500, 4000, 3000, 1.0, 50);
  vehicles[0].axleAngle = 15.0 / 180.0 * std::acos(-1);
  std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  // std::cout << vehicles[1].x << " " << vehicles[1].y << std::endl;
  for (int i = 0; i < 30; i++) {
    result = tspSetTime(6);
    std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  }
  // std::cout << vehicles[1].x << " " << vehicles[1].y << std::endl;
  result = tspSetTime(1000);
  std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  // std::cout << vehicles[1].x << " " << vehicles[1].y << std::endl;

  return app.exec();
}
