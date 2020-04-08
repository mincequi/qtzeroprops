SOURCES += \
    main.cpp

LIBS += -L$$OUT_PWD/../../src/ -lsrc
INCLUDEPATH += $$PWD/../../include
PRE_TARGETDEPS += $$OUT_PWD/../../src/libsrc.a
