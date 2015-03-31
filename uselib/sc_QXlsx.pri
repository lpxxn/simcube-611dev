message("---xlsx-LIbs")
INCLUDEPATH *= $$THIRDPARTYINCLUDE
message($$THIRDPARTYINCLUDE)

message($$INCLUDEPATH)

DEFINES += QT_BUILD_XLSX_LIB
message($$QT_BUILD_XLSX_LIB)

message($$DEFINES)

win32-msvc*:contains(QMAKE_HOST.arch, x86_64): {
    LIBS += -L$$SIMCUBE_SOURCE_TREE/lib/QXlsx/win64/msvc -l$$qtLibraryName(Qt5Xlsx)
    FILES_COPY_SRC = $$SIMCUBE_SOURCE_TREE/lib/QXlsx/win64/msvc/$$qtLibraryName(Qt5Xlsx).dll
}

win32-g++:contains(QMAKE_HOST.arch, x86_64): {
    LIBS += -L$$SIMCUBE_SOURCE_TREE/lib/QXlsx/win64/gcc -l$$qtLibraryName(Qt5Xlsx)
    FILES_COPY_SRC = $$SIMCUBE_SOURCE_TREE/lib/QXlsx/win64/gcc/$$qtLibraryName(Qt5Xlsx).dll
    message("Enter 1")
}

win32-msvc*:contains(QMAKE_HOST.arch, x86): {
    LIBS += -L$$SIMCUBE_SOURCE_TREE/lib/QXlsx/win32/msvc -l$$qtLibraryName(Qt5Xlsx)
    FILES_COPY_SRC = $$SIMCUBE_SOURCE_TREE/lib/QXlsx/win32/msvc/$$qtLibraryName(Qt5Xlsx).dll
    message("Enter 2")
}

win32-g++:contains(QMAKE_HOST.arch, x86): {
    LIBS += -L$$SIMCUBE_SOURCE_TREE/lib/QXlsx/win32/gcc -l$$qtLibraryName(Qt5Xlsx)
    FILES_COPY_SRC = $$SIMCUBE_SOURCE_TREE/lib/QXlsx/win32/gcc/$$qtLibraryName(Qt5Xlsx).dll
    message("Enter 3")
}

unix: contains(QMAKE_HOST.arch, x86_64): {
    LIBS *= -L$$SIMCUBE_SOURCE_TREE/lib/QXlsx/linux64 -l$$qtLibraryName(Qt5Xlsx)
    QMAKE_RPATHDIR += $$SIMCUBE_SOURCE_TREE/lib/QXlsx/linux64
    FILES_COPY_SRC = $$SIMCUBE_SOURCE_TREE/lib/QXlsx/linux64/libQXlsx.so
    message("Enter 4")
}


message($$LIBS)
message($$FILES_COPY_SRC)

#拷贝依赖的动态链接库到app路径下
$$copyFile($$FILES_COPY_SRC, $$SIMCUBE_APP_PATH)
