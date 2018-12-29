#include "obstacles.h"
#include "simulation_lines.h"
#include <QBrush>
#include <QColor>
#include <QPainter>

Obstacles::Obstacles(QQuickItem *parent) : QQuickPaintedItem(parent) {}

void Obstacles::paint(QPainter *painter) {
  if (m_meterInPixels <= 0) {
    return;
  }

  QBrush brush(QColor("#000000"));
  painter->setBrush(brush);
  for (auto line : lines) {
    painter->drawLine(line.line.start.x * m_meterInPixels,
                      line.line.start.y * m_meterInPixels,
                      line.line.end.x * m_meterInPixels,
                      line.line.end.y * m_meterInPixels);
  }
  /*
  QBrush brush1((QColor(m_color1)));
  QBrush brush2((QColor(m_color2)));
  painter->fillRect(contentsBoundingRect(), brush1);

  for (int y = -m_step + (static_cast<int>(height() / 2.0) % m_step);
       y < height(); y += m_step) {
    for (int x = -m_step + (static_cast<int>(width() / 2.0) % m_step);
         x < width(); x += m_step) {
      if (((x + y + m_step * 2) / m_step) % 2 == 0) {
        painter->fillRect(QRectF(x, y, m_step, m_step), brush2);
      }
    }
  }*/
}

qreal Obstacles::meterInPixels() { return m_meterInPixels; }

void Obstacles::setMeterInPixels(qreal meterInPixels) {
  if (m_meterInPixels != meterInPixels) {
    m_meterInPixels = meterInPixels;
    emit meterInPixelsChanged();
  }
}
