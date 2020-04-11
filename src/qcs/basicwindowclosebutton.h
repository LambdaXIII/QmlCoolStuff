#ifndef BASICWINDOWCLOSEBUTTON_H
#define BASICWINDOWCLOSEBUTTON_H

#include "cool_global.h"

#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

COOL_NS_BEGIN

class COOL_SHARED_EXPORT BasicWindowCloseButton
  : public QQuickPaintedItem {
  Q_OBJECT
  COOL_WRITABLE_PROPERTY(QColor, fillColor)
  COOL_WRITABLE_PROPERTY(QColor, strokeColor)

  COOL_READONLY_PROPERTY(bool, hovered)
  COOL_READONLY_PROPERTY(bool, down)

public:
  explicit BasicWindowCloseButton(QQuickItem* p = nullptr);

  void paint(QPainter* painter) override;

  Q_INVOKABLE bool contains(const QPointF& p) const override;

protected:
  QPainterPath trianglePath() const;
  void hoverEnterEvent(QHoverEvent*) override;
  void hoverLeaveEvent(QHoverEvent*) override;
  void mousePressEvent(QMouseEvent*) override;
  void mouseReleaseEvent(QMouseEvent* mouse) override;

signals:
  void clicked(QMouseEvent* mouse);
};

COOL_NS_END

#endif // BASICWINDOWCLOSEBUTTON_H
