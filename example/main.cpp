#include "simulation.h"
#include "vehicle.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  Simulation simulation;
  engine.rootContext()->setContextProperty("simulation", &simulation);
  qmlRegisterType<Vehicle>("Vehicle", 1, 0, "Vehicle");

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;
  return app.exec();
}
