TEMPLATE = app
TARGET = Ship-GUI

QT += core gui widgets

SOURCES += $$files($$PWD/src/*.cpp, true)
HEADERS += $$files($$PWD/include/*.h, true)
FORMS += $$files($$PWD/ui/*.ui, true)

DESTDIR = build
OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
UI_DIR = $$DESTDIR/ui

INCLUDEPATH += include
RESOURCES += resources/styles.qrc resources/images.qrc

QMAKE_MOC_DIR = $$MOC_DIR
QMAKE_UI_DIR = $$UI_DIR

QMAKE_CXXFLAGS += -g -Wall

