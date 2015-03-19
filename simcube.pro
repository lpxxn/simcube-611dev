include(simcube.pri)

#version check qt
!minQtVersion(5, 3, 0) {
    message("Cannot build SimCube with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.3.0.")
}

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = src
