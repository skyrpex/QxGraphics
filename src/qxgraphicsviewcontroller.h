#ifndef QXGRAPHICSVIEWCONTROLLER_H
#define QXGRAPHICSVIEWCONTROLLER_H

#include <QObject>
#include <QGraphicsView>
#include <QContextMenuEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>

class QxGraphicsViewController : public QObject
{
  Q_OBJECT
public:
  virtual void contextMenuEvent(QGraphicsView *view, QContextMenuEvent *event) {}
  virtual bool wheelEvent(QGraphicsView *view, QWheelEvent *event) {return false;}
  virtual bool mouseDoubleClickEvent(QGraphicsView *view, QMouseEvent *event) {return false;}
  virtual bool mousePressEvent(QGraphicsView *view, QMouseEvent *event) {return false;}
  virtual bool mouseMoveEvent(QGraphicsView *view, QMouseEvent *event) {return false;}
  virtual bool mouseReleaseEvent(QGraphicsView *view, QMouseEvent *event) {return false;}
  virtual bool keyPressEvent(QGraphicsView *view, QKeyEvent *event) {return false;}
  virtual bool keyReleaseEvent(QGraphicsView *view, QKeyEvent *event) {return false;}
  virtual void drawBackground(QGraphicsView *view, QPainter *painter, const QRectF &rect) {}
  virtual void drawForeground(QGraphicsView *view, QPainter *painter, const QRectF &rect) {}

protected:
  virtual bool installTo(QGraphicsView *view) {return true;}
  virtual void uninstallFrom(QGraphicsView *view) {}

private:
  friend class QxGraphicsView;
};

#endif // QXGRAPHICSVIEWCONTROLLER_H
