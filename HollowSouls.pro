QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arrow.cpp \
    block.cpp \
    bow.cpp \
    circularmotion.cpp \
    dash.cpp \
    demon.cpp \
    enemy.cpp \
    furry.cpp \
    game.cpp \
    healthbar.cpp \
    main.cpp \
    motion.cpp \
    player.cpp \
    sprite.cpp \
    thebox.cpp \
    weapon.cpp

HEADERS += \
    arrow.h \
    block.h \
    bow.h \
    circularmotion.h \
    dash.h \
    demon.h \
    enemy.h \
    furry.h \
    game.h \
    healthbar.h \
    macros.h \
    motion.h \
    player.h \
    sprite.h \
    thebox.h \
    weapon.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    thebox.ui

RESOURCES += \
    sprites.qrc
