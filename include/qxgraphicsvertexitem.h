#ifndef VERTEX_H
#define VERTEX_H

#include "qxgraphics_global.h"
#include <QObject>
#include <QGraphicsRectItem>

class QXGRAPHICS_API QxGraphicsVertexItem : public QObject, public QGraphicsRectItem
{
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  QxGraphicsVertexItem();
  QxGraphicsVertexItem(const QPointF &pos);

  QVariant itemChange(GraphicsItemChange change, const QVariant &value);

signals:
  void posChanged();
};

#endif // VERTEX_H
