TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    glad.c \
    shadercontroller.cpp \
    coordinates.cpp \
    baseshape.cpp

LIBS += -lGL -lglfw -ldl

HEADERS += \
    shadercontroller.h \
    coordinates.h \
    baseshape.h
