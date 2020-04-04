#include "basiccutcornerbox.h"

#include <QPainter>

COOL_NS_BEGIN

BasicCutCornerBox::BasicCutCornerBox(QQuickItem* p)
  : QQuickPaintedItem(p)
  , m_strokeWidth(4)
  , m_cutSize(10)
  , m_backColor(Qt::black)
  , m_strokeColor(Qt::red) {
}

void BasicCutCornerBox::paint(QPainter* painter) {
  auto core_path = cutCornerPath(m_strokeWidth);

  //画背景
  painter->fillPath(core_path, QBrush(m_backColor));

  //画边框
  auto stroke_path = cutCornerPath().subtracted(core_path);
  painter->fillPath(stroke_path, QBrush(m_strokeColor));
}

QPainterPath BasicCutCornerBox::cutCornerPath(qreal offset) const {
  QPainterPath result;

  if (width() - offset < m_cutSize / 2 + offset
      && height() - offset < m_cutSize / 2 + offset)
    return result; //宽高太小的话就不画啦

  if (width() - offset * 2 <= 0 || height() - offset * 2 <= 0)
    return result;

  if (width() < m_cutSize + offset * 1.5) //如果宽度小于切角宽度
    result.moveTo(width() - offset,
      m_cutSize - width() + offset * 2.5); //此点代替切角顶部点
  else
    result.moveTo(m_cutSize + offset / 2, 0 + offset); //切角顶部点

  if (width() >= m_cutSize) //只有宽度大于等于切点时才有右上角顶点
    result.lineTo(width() - offset, 0 + offset); //右上角顶点

  result.lineTo(width() - offset, height() - offset); //右下角顶点

  if (height() >= m_cutSize) //只有高度大于等于切角宽度时才有左下角顶点
    result.lineTo(0 + offset, height() - offset); //左下角顶点

  if (height() < m_cutSize + offset * 1.5) //如果高度小于切角宽度
    result.lineTo(m_cutSize - height() + offset * 2.5,
      height() - offset); //此点代替切角左侧点
  else
    result.lineTo(0 + offset, m_cutSize + offset / 2); //切角左侧点

  result.closeSubpath(); //关闭路径，自动链接最后一段斜线
  return result;
}

COOL_NS_END
