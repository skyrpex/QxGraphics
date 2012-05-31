QT = core gui
TARGET = QxGraphics
TEMPLATE = lib
DESTDIR = $$PWD/bin
DEFINES += QXGRAPHICS_LIBRARY

SOURCES += \
    $$PWD/src/qxgraphicsview.cpp \
    $$PWD/src/qxgraphicslineitem.cpp \
    $$PWD/src/qxgraphicsedgeitem.cpp \
    $$PWD/src/qxgraphicspolygonitem.cpp \
    $$PWD/src/qxgraphicsvertexitem.cpp

HEADERS  += \
    $$PWD/include/qxgraphics_global.h \
    $$PWD/include/QxGraphicsView \
    $$PWD/include/QxGraphicsLineItem \
    $$PWD/include/QxGraphicsPolygonItem \
    $$PWD/include/QxGraphicsVertexItem \
    $$PWD/include/QxGraphicsEdgeItem \
    $$PWD/include/qxgraphicsview.h \
    $$PWD/include/qxgraphicslineitem.h \
    $$PWD/include/qxgraphicspolygonitem.h \
    $$PWD/include/qxgraphicsvertexitem.h \
    $$PWD/include/qxgraphicsedgeitem.h \
    $$PWD/include/qxgraphicsviewcontroller.h

INCLUDEPATH += $$PWD/include
