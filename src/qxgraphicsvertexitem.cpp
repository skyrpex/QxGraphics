#include "qxgraphicsvertexitem.h"
#include <QBrush>
#include <QDebug>

static const qreal VertexWidth = 7.5;

QxGraphicsVertexItem::QxGraphicsVertexItem() :
  QGraphicsRectItem(-VertexWidth/2, -VertexWidth/2, VertexWidth, VertexWidth)
{
  this->setFlags(ItemIsMovable |
                 ItemIgnoresTransformations |
                 ItemSendsScenePositionChanges);
  this->setCacheMode(DeviceCoordinateCache);
  this->setBrush(Qt::lightGray);
}

QxGraphicsVertexItem::QxGraphicsVertexItem(const QPointF &pos) :
  QGraphicsRectItem(-VertexWidth/2, -VertexWidth/2, VertexWidth, VertexWidth)
{
  this->setFlags(ItemIsMovable |
                 ItemIgnoresTransformations |
                 ItemSendsScenePositionChanges);
  this->setCacheMode(DeviceCoordinateCache);
  this->setBrush(Qt::lightGray);
  this->setPos(pos);
}

QVariant QxGraphicsVertexItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
  switch(change)
  {
  case ItemPositionHasChanged:
    emit posChanged();
    break;

  default:
    break;
  }

  return QGraphicsRectItem::itemChange(change, value);
}
