#ifndef BASICCUTCORNERBOX_H
#define BASICCUTCORNERBOX_H

#include "cool_global.h"

#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

COOL_NS_BEGIN

class COOL_SHARED_EXPORT BasicCutCornerBox: public QQuickPaintedItem {
  Q_OBJECT

  COOL_WRITABLE_PROPERTY(qreal, strokeWidth)
  COOL_WRITABLE_PROPERTY(qreal, cutSize)
  COOL_WRITABLE_PROPERTY(QColor, backColor)
  COOL_WRITABLE_PROPERTY(QColor, strokeColor)

public:
  explicit BasicCutCornerBox(QQuickItem* p = nullptr);

  /**
   * @brief 标准绘制方法
   * @param painter
   */
  void paint(QPainter* painter) override;

protected:
  /**
   * @brief 实时计算边框路径
   * @param offset 是边框收缩的距离
   * @return
   */
  QPainterPath cutCornerPath(qreal offset = 0) const;
};

COOL_NS_END

#endif // BASICCUTCORNERBOX_H
