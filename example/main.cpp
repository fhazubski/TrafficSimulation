#include "tslib/api.h"
#include "tslib/types.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  TSP::tsp_vehicle *vehicles = tspReserveMemory(100);
  tspAddVehicle(0.0, 0.0, 1500, 4000, 3000, 0.0, 50);
  std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  tspSetTime(1000);
  std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;
  tspSetTime(10000);
  std::cout << vehicles[0].x << " " << vehicles[0].y << std::endl;

  return app.exec();
}
