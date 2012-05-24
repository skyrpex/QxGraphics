#include <qxgraphicslineitem.h>
#include <QBrush>
#include <QGraphicsSceneContextMenuEvent>
#include <QPainter>
#include <QMenu>
#include <QCursor>
#include <QDebug>

////////////////////////////////////////////////////////////////////////////////////////////////////
static const qreal MinSplitDistance = 4.0;

////////////////////////////////////////////////////////////////////////////////////////////////////
QxGraphicsLineItem::QxGraphicsLineItem()
{
//  this->setCursor(Qt::CrossCursor);
  this->setZValue(-1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QxGraphicsLineItem::QxGraphicsLineItem(const QLineF &line)
{
  this->setZValue(-1);
  this->setLine(line);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void QxGraphicsLineItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
  if(qFuzzyCompare(m_line.length(), qreal(0.0)))
     return;
  painter->drawLine(m_line);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QRectF QxGraphicsLineItem::boundingRect() const
{
  return QRectF(m_line.p1(), m_line.p2())
      .normalized()
      .adjusted(-MinSplitDistance, -MinSplitDistance,
                MinSplitDistance, MinSplitDistance);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool QxGraphicsLineItem::collidesWithPath(const QPainterPath &path,
                                        Qt::ItemSelectionMode mode) const
{
  return this->contains(path.currentPosition());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool QxGraphicsLineItem::contains(const QPointF &point) const
{
  return this->distanceTo(point) < MinSplitDistance;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// http://local.wasp.uwa.edu.au/~pbourke/geometry/pointline/
QPointF QxGraphicsLineItem::nearestPoint(const QPointF &point) const
{
  if(m_line.isNull()) return m_line.p1();

  qreal x1 = m_line.p1().x();
  qreal x2 = m_line.p2().x();
  qreal x3 = point.x();
  qreal y1 = m_line.p1().y();
  qreal y2 = m_line.p2().y();
  qreal y3 = point.y();

  qreal x31 = x3 - x1;
  qreal x21 = x2 - x1;
  qreal y31 = y3 - y1;
  qreal y21 = y2 - y1;
  qreal len = m_line.length();
  qreal u = (x31*x21 + y31*y21) / (len*len);

  return m_line.pointAt(qMax(qMin(u, 1.0), 0.0));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
qreal QxGraphicsLineItem::distanceTo(const QPointF &point) const
{
  return QLineF(point, this->nearestPoint(point)).length();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QLineF QxGraphicsLineItem::line() const
{
  return m_line;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void QxGraphicsLineItem::setLine(const QLineF &line)
{
  this->prepareGeometryChange();
  m_line = line;
}
