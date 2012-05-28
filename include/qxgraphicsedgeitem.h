#ifndef EDGE_H
#define EDGE_H

#include "qxgraphics_global.h"
#include <QObject>
#include <qxgraphicslineitem.h>
#include <qxgraphicsvertexitem.h>

class QXGRAPHICS_API QxGraphicsEdgeItem : public QObject, public QxGraphicsLineItem
{
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  QxGraphicsEdgeItem(QxGraphicsVertexItem *v1, QxGraphicsVertexItem *v2);

  QxGraphicsVertexItem *v1() const;
  QxGraphicsVertexItem *v2() const;

private slots:
  void updateLine();

private:
  QxGraphicsVertexItem *m_v1;
  QxGraphicsVertexItem *m_v2;
};

#endif // EDGE_H
