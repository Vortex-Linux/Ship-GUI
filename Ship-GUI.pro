TEMPLATE = app
TARGET = Ship-GUI

QT += core gui widgets

# Source files
SOURCES += src/main.cpp \
           src/nav.cpp

HEADERS += include/nav.h

FORMS += ui/nav.ui

DESTDIR = build

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
UI_DIR = $$DESTDIR/ui

INCLUDEPATH += include
RESOURCES += resources.qrc

QMAKE_MOC_DIR = $$MOC_DIR
QMAKE_UI_DIR = $$UI_DIR

