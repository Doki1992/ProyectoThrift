#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T19:20:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProThrift_1
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -Wall
              INCLUDEPATH += -l/usr/local/include/thrift
              LIBS += -L/usr/local/lib -lthrift

SOURCES +=\
        mainwindow.cpp \
    proprueba_constants.cpp \
    proprueba_types.cpp \
    ProThrift.cpp \
    ProThrift_server.skeleton.cpp \
    main.cpp \
    worker.cpp \
    arbol_jugador.cpp

HEADERS  += mainwindow.h \
    proprueba_constants.h \
    proprueba_types.h \
    ProThrift.h \
    worker.h \
    arbol_avl.h \
    arbol_jugador.h \
    definiciones.h \
    definiciones_avl.h \
    d_iterador.h \
    listagenerica.h \
    nodo_avl.h \
    nodo_fila.h \
    nodogenerico.h \
    personaje.h

FORMS    += mainwindow.ui
