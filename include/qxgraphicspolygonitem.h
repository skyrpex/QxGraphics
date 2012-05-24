#ifndef POLYGON_H
#define POLYGON_H

#include <QGraphicsItemGroup>
#include <QPolygonF>
#include <QObject>
#include <qxgraphicsvertexitem.h>
#include <qxgraphicsedgeitem.h>

class QxGraphicsPolygonItem : public QObject, public QGraphicsItemGroup
{
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  QxGraphicsPolygonItem();
  QxGraphicsPolygonItem(const QPolygonF &polygon);

  void setPolygon(const QPolygonF &polygon);



  QPolygonF polygon() const;
  bool isClosed() const;
  bool isEmpty() const;

  void addVertex(QxGraphicsVertexItem *vertex);
  bool removeVertex(QxGraphicsVertexItem *vertex);
  void close();

  void updateBoundaryEdges();

public slots:
  void setBoundaryVerticesVisible(bool visible);

private:
  void clear();
  void clearBoundaryEdges();

  QxGraphicsEdgeItem *createEdge(QxGraphicsVertexItem *v1, QxGraphicsVertexItem *v2);
  QxGraphicsEdgeItem *findEdge1(QxGraphicsVertexItem *v);
  QxGraphicsEdgeItem *findEdge2(QxGraphicsVertexItem *v);

  QList<QxGraphicsVertexItem*> m_boundary;
  QList<QxGraphicsEdgeItem*> m_edges;
  bool m_closed;
  bool m_boundaryVisible;
};

#endif // POLYGON_H
