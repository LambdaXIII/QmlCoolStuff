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
  COOL_WRITABLE_PROPERTY(bool, hasBack)
  COOL_WRITABLE_PROPERTY(bool, hasStroke)

public:
  explicit BasicCutCornerBox(QQuickItem* p = nullptr);

  /**
   * @brief 标准绘制方法
   * @param painter
   */
  void paint(QPainter* painter) override;

  Q_INVOKABLE bool contains(const QPointF& p) const override;

protected:
  /**
   * @brief 实时计算边框路径
   * @param offset 是边框收缩的距离
   * @return
   */
  QPainterPath cutCornerPath(qreal offset = 0) const;

  /**
   * @brief updateStrokes 发起边框部分画面更新
   * @param old_strokeWidth 边框部分变更前内容
   * @param new_strokeWidth 边框部分变更后内容
   */
  Q_SLOT void updateStrokes(
    qreal old_strokeWidth, qreal new_strokeWidth);

  /** 只更新左上角 */
  Q_SLOT void updateTLCorner(qreal old_cutSize, qreal new_cutSize);
};

COOL_NS_END

#endif // BASICCUTCORNERBOX_H
