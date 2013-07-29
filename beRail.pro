APP_NAME = beRail

CONFIG += qt warn_on cascades10
QT += network xml
LIBS += -lbbdata -lbbutilityi18n

include(config.pri)

lupdate_inclusion {
    SOURCES += \
        $$BASEDIR/../src/*.cpp $$BASEDIR/../assets/*.qml $$BASEDIR/../src/Services/*.cpp $$BASEDIR/../src/ViewModels/*.cpp
}