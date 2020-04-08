TEMPLATE = lib
QT     -= gui
QT     += bluetooth websockets
CONFIG += staticlib create_prl

QMAKE_CXXFLAGS += -Werror

DEFINES += QZEROCONF_STATIC MSGPACK_NO_PACKTYPES
include(../thirdparty/QtZeroConf/qtzeroconf.pri)
include(../thirdparty/qmsgpack/qmsgpack.pri)

SOURCES += \
    BleClientSession.cpp \
    BleServer.cpp \
    BleServerSession.cpp \
    QZeroPropsBleClient.cpp \
    QZeroPropsClient.cpp \
    QZeroPropsServer.cpp \
    QZeroPropsServerPrivate.cpp \
    QZeroPropsService.cpp \
    QZeroPropsServicePrivate.cpp \
    QZeroPropsWsService.cpp \
    QZeroPropsWsServer.cpp

HEADERS += \
    ../include/QtZeroProps/QZeroPropsTypes.h \
    ../include/QtZeroProps/QZeroPropsClient.h \
    ../include/QtZeroProps/QZeroPropsServer.h \
    ../include/QtZeroProps/QZeroPropsService.h \
    BleClientSession.h \
    BleServerSession.h \
    QZeroPropsBleClient.h \
    QZeroPropsBleService.h \
    QZeroPropsServerPrivate.h \
    QZeroPropsServicePrivate.h \
    QZeroPropsWsService.h \
    QZeroPropsWsServer.h

INCLUDEPATH += \
    ../include
