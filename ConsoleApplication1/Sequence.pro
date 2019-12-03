TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    Animal.cpp

HEADERS += \
    Sequence.h \
    acutest.h \
    ListSequence.h \
    VectorSequence.h \
    ArraySequence.h \
    Animal.h \
    TestInt.h \
    TestAnimal.h

