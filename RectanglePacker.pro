TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

TARGET = algo

SOURCES += main.cpp \
    rectangle.cpp \
    packer.cpp \
    levelh.cpp \
    point.cpp

HEADERS += \
    rectangle.h \
    packer.h \
    levelh.h \
    userdefines.h \
    point.h
