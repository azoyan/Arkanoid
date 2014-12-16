#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T13:56:07
#
#-------------------------------------------------

QT       += core gui

TARGET = Arkanoid
TEMPLATE = app


SOURCES += main.cpp \
    arkanoid.cpp \
    elements/element.cpp \
    elements/platform.cpp \
    elements/ball.cpp \
    elements/brick.cpp \
    elements/properties/health.cpp \
    elements/properties/touchstate.cpp

HEADERS  += \
    arkanoid.h \
    elements/element.h \
    elements/platform.h \
    elements/ball.h \
    elements/brick.h \
    elements/properties/health.h \
    elements/properties/touchstate.h
