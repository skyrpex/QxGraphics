TARGET = QxGraphics
DESTDIR = $$PWD/bin
TEMPLATE = lib
DEFINES += QXGRAPHICS_LIBRARY

SOURCES += \
    src/qxgraphicsview.cpp \
    src/qxgraphicslineitem.cpp \
    src/qxgraphicsedgeitem.cpp \
    src/qxgraphicspolygonitem.cpp \
    src/qxgraphicsvertexitem.cpp

INCLUDEPATH += include

HEADERS += \
    include/qxgraphics_global.h \
    include/qxgraphicsview.h \
    include/qxgraphicslineitem.h \
    include/qxgraphicspolygonitem.h \
    include/qxgraphicsvertexitem.h \
    include/qxgraphicsedgeitem.h
