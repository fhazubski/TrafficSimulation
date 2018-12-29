#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "simulation.h"
#include <QQuickPaintedItem>

class Obstacles : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(qreal meterInPixels READ meterInPixels WRITE setMeterInPixels
                 NOTIFY meterInPixelsChanged)

public:
  Obstacles(QQuickItem *parent = 0);
  void paint(QPainter *painter);

  qreal meterInPixels();
  Simulation *simulation();

  void setMeterInPixels(qreal meterInPixels);

signals:
  void meterInPixelsChanged();

private:
  qreal m_meterInPixels;
};

#endif // OBSTACLES_H
