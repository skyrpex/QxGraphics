#ifndef GRAPHICSLINEITEM_H
#define GRAPHICSLINEITEM_H

#include "qxgraphics_global.h"
#include <QGraphicsItem>
#include <QLineF>

class QXGRAPHICS_API QxGraphicsLineItem : public QGraphicsItem
{
public:
  QxGraphicsLineItem();
  QxGraphicsLineItem(const QLineF &line);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

  QRectF  boundingRect() const;
  bool    collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const;
  bool    contains(const QPointF &point) const;
  QPointF nearestPoint(const QPointF &point) const;
  qreal   distanceTo(const QPointF &point) const;
  QLineF  line() const;

  void setLine(const QLineF &line);

private:
  QLineF m_line;
};

#endif // GRAPHICSLINEITEM_H
