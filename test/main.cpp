#include <QApplication>
#include <QxGraphicsView>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QxGraphicsView view(new QGraphicsScene);

  view.show();
  return app.exec();
}
