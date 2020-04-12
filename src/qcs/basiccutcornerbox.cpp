#include "basiccutcornerbox.h"

#include <QPainter>
#include <QRectF>
#include <array>

COOL_NS_BEGIN

BasicCutCornerBox::BasicCutCornerBox(QQuickItem* p)
  : QQuickPaintedItem(p)
  , m_strokeWidth(4)
  , m_cutSize(10)
  , m_backColor(Qt::black)
  , m_strokeColor(Qt::red)
  , m_hasBack(true)
  , m_hasStroke(true) {
  connect(this, &BasicCutCornerBox::strokeWidthInternalChanged, this,
    &BasicCutCornerBox::updateStrokes);
  connect(this, &BasicCutCornerBox::cutSizeInternalChanged, this,
    &BasicCutCornerBox::updateTLCorner);
  connect(
    this, &BasicCutCornerBox::backColorChanged, [&] { update(); });
  connect(
    this, &BasicCutCornerBox::strokeColorChanged, [&] { update(); });
  connect(this, &BasicCutCornerBox::hasBackChanged, [&] { update(); });
  connect(this, &BasicCutCornerBox::hasStrokeChanged,
    [&] { updateStrokes(m_strokeWidth, m_strokeWidth); });
}

void BasicCutCornerBox::paint(QPainter* painter) {
  auto core_path = cutCornerPath(m_strokeWidth);

  //画背景
  if (m_hasBack)
    painter->fillPath(core_path, QBrush(m_backColor));

  //画边框
  if (m_hasStroke) {
    auto stroke_path = cutCornerPath().subtracted(core_path);
    painter->fillPath(stroke_path, QBrush(m_strokeColor));
  }
}

bool BasicCutCornerBox::contains(const QPointF& p) const {
  QRectF roi(0, 0, width(), height()); //外边框范围
  if (! roi.contains(p))
    return false; //超出范围直接判负

  //如果处于切掉的角里也判负
  if (p.x() + p.y() < m_cutSize)
    return false;

  return true;
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

void BasicCutCornerBox::updateStrokes(
  qreal old_strokeWidth, qreal new_strokeWidth) {
  //取最大值
  qreal _stroke_w = old_strokeWidth > new_strokeWidth ?
                      old_strokeWidth :
                      new_strokeWidth;
  //缓存属性
  qreal _cut_size = m_cutSize;
  qreal w = width();
  qreal h = height();
  qreal delta_cut_size = _cut_size + _stroke_w / 2;
  //新建一系列切片
  std::array<QRectF, 5> slices;
  slices[0] = { 0, 0, delta_cut_size, delta_cut_size }; //左上角方块
  slices[1] = { delta_cut_size, 0, w - delta_cut_size,
    _stroke_w }; //顶部边框范围
  slices[2] = { w - _stroke_w, _stroke_w, _stroke_w,
    h - _stroke_w * 2 };                          //右侧边框范围
  slices[3] = { 0, h - _stroke_w, w, _stroke_w }; //底部边框范围
  slices[4] = { 0, delta_cut_size, _stroke_w,
    h - delta_cut_size - _stroke_w }; //左侧边框范围

  for (const auto& r : slices)
    update(r.toRect());
}

void BasicCutCornerBox::updateTLCorner(
  qreal old_cutSize, qreal new_cutSize) {
  qreal _cut_size =
    old_cutSize > new_cutSize ? old_cutSize : new_cutSize;
  qreal _stroke_w = m_strokeWidth;
  QRectF box(
    0, 0, _cut_size + _stroke_w / 2, _cut_size + _stroke_w / 2);
  update(box.toRect());
}

COOL_NS_END
