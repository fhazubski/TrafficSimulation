win32: LIBS += -L$$PWD/../tslib/build/lib_install/ -ltslib

INCLUDEPATH += $$PWD/../tslib/build/include_install
DEPENDPATH += $$PWD/../tslib/build/lib_install

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../tslib/build/lib_install/tslib.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../tslib/build/lib_install/libtslib.a

HEADERS += \
    $$PWD/../tslib/build/include_install/tslib/api.h \
    $$PWD/../tslib/build/include_install/tslib/tslib_export.h \
    $$PWD/../tslib/build/include_install/tslib/types.h
