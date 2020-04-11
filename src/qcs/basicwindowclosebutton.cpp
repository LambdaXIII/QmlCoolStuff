#include "basicwindowclosebutton.h"

#include <QPainter>

COOL_NS_BEGIN

BasicWindowCloseButton::BasicWindowCloseButton(QQuickItem* p)
  : QQuickPaintedItem(p) {
  connect(
    this, &BasicWindowCloseButton::fillColorChanged, [&] { update(); });
  connect(this, &BasicWindowCloseButton::strokeColorChanged,
    [&] { update(); });
  setAcceptHoverEvents(true);
  setAcceptedMouseButtons(Qt::LeftButton);
}

void BasicWindowCloseButton::paint(QPainter* painter) {
  auto p = trianglePath();
  painter->fillPath(p, QBrush(m_fillColor));
  painter->strokePath(p, QPen(m_strokeColor, 2));
}

bool BasicWindowCloseButton::contains(const QPointF& p) const {
  return p.x() + p.y() <= width();
}

QPainterPath BasicWindowCloseButton::trianglePath() const {
  QPainterPath p;
  p.moveTo(0, height());
  p.lineTo(0, 0);
  p.lineTo(width(), 0);
  p.closeSubpath();
  return p;
}

void BasicWindowCloseButton::hoverEnterEvent(QHoverEvent*) {
  update_hovered(true);
}

void BasicWindowCloseButton::hoverLeaveEvent(QHoverEvent*) {
  update_hovered(false);
}

void BasicWindowCloseButton::mousePressEvent(QMouseEvent*) {
  update_down(true);
}

void BasicWindowCloseButton::mouseReleaseEvent(QMouseEvent* mouse) {
  update_down(false);
  if (contains(mouse->pos()))
    emit clicked(mouse);
}

COOL_NS_END
