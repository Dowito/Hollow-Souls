QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Screens/gameover.cpp \
    Screens/loadscreen.cpp \
    Screens/menu.cpp \
    Screens/world.cpp \
    arrow.cpp \
    block.cpp \
    bow.cpp \
    circularblock.cpp \
    circularmotion.cpp \
    dash.cpp \
    demon.cpp \
    enemy.cpp \
    furry.cpp \
    game.cpp \
    healthbar.cpp \
    main.cpp \
    motion.cpp \
    motionblock.cpp \
    player.cpp \
    spike.cpp \
    sprite.cpp \
    weapon.cpp

HEADERS += \
    Screens/gameover.h \
    Screens/loadscreen.h \
    Screens/menu.h \
    Screens/world.h \
    arrow.h \
    block.h \
    bow.h \
    circularblock.h \
    circularmotion.h \
    dash.h \
    demon.h \
    enemy.h \
    furry.h \
    game.h \
    healthbar.h \
    macros.h \
    motion.h \
    motionblock.h \
    player.h \
    spike.h \
    sprite.h \
    weapon.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=

RESOURCES += \
    sprites.qrc

DISTFILES +=
