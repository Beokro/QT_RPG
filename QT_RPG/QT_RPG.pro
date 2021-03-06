#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T00:22:38
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_RPG
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Life.cpp \
    Skill.cpp \
    Item.cpp \
    Hero.cpp \
    Monster.cpp \
    Bag.cpp \
    Dungeon.cpp \
    NPC.cpp \
    World.cpp

HEADERS  += \
    Game.h \
    Life.h \
    Skill.h \
    Item.h \
    Hero.h \
    Monster.h \
    Bag.h \
    Dungeon.h \
    NPC.h \
    World.h

FORMS    += mainwindow.ui

RESOURCES += \
    src.qrc
