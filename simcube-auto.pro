include(simcube.pri)

#version check qt
!minQtVersion(5, 2, 0) {
    message("Cannot build SimCube with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.2.0.")
}

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = src #test

files = $$files($$PWD/translations/*_??.ts)
for(file, files) {
    TRANSLATIONS += $$file
}

OTHER_FILES += $$TRANSLATIONS
