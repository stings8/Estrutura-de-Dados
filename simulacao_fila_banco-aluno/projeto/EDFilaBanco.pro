TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES += main.cpp \
    Libs/pintor.cpp \
    Libs/assetmanager.cpp \
    simulacao.cpp

HEADERS += \
    Libs/pintor.h \
    Libs/assetmanager.h \
    globais.h \
    simulacao.h

