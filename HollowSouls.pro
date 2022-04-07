QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    block.cpp \
    game.cpp \
    main.cpp \
    motion.cpp \
    player.cpp \
    sprite.cpp \
    thebox.cpp \
    weapon.cpp

HEADERS += \
    block.h \
    game.h \
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
