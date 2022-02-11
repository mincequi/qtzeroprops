cmake_minimum_required(VERSION 3.7)

project(qtzeroprops)

add_definitions(-DQZEROCONF_STATIC -DMSGPACK_NO_PACKTYPES)
add_subdirectory(thirdparty/QtZeroConf)

find_package(Qt5Bluetooth)
find_package(Qt5WebSockets)

add_library(${PROJECT_NAME} STATIC
    include/QtZeroProps/QZeroPropsClient.h
    include/QtZeroProps/QZeroPropsServer.h
    include/QtZeroProps/QZeroPropsService.h

    src/BleClientSession.cpp
    src/QZeroPropsBleClient.cpp
    src/QZeroPropsClient.cpp
    src/QZeroPropsServer.cpp
    src/QZeroPropsServerPrivate.cpp
    src/QZeroPropsService.cpp
    src/QZeroPropsServicePrivate.cpp
    src/QZeroPropsWsServer.h
    src/QZeroPropsWsServer.cpp
    src/QZeroPropsWsService.h
    src/QZeroPropsWsService.cpp

    #thirdparty/QtZeroConf/qzeroconf.h
    #thirdparty/QtZeroConf/avahi-qt/qt-watch.h
    #thirdparty/QtZeroConf/avahi-qt/qt-watch_p.h

    #thirdparty/QtZeroConf/avahi-qt/qt-watch.cpp
    #thirdparty/QtZeroConf/avahiclient.cpp
    #thirdparty/QtZeroConf/avahi-qt/qt-watch.cpp

    thirdparty/qmsgpack/src/msgpack.cpp
    thirdparty/qmsgpack/src/msgpackcommon.cpp
    thirdparty/qmsgpack/src/msgpackstream.cpp
    thirdparty/qmsgpack/src/private/pack_p.cpp
    thirdparty/qmsgpack/src/private/unpack_p.cpp

    thirdparty/qmsgpack/src/msgpack.h
    thirdparty/qmsgpack/src/endianhelper.h
    thirdparty/qmsgpack/src/msgpackcommon.h
    thirdparty/qmsgpack/src/msgpack_export.h
    thirdparty/qmsgpack/src/msgpackstream.h
    thirdparty/qmsgpack/src/private/pack_p.h
    thirdparty/qmsgpack/src/private/unpack_p.h
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
PRIVATE
    thirdparty/QtZeroConf
    thirdparty/qmsgpack/src
)

target_link_libraries(${PROJECT_NAME}
    avahi-common
    avahi-client
    QtZeroConf
    Qt5::Bluetooth
    Qt5::WebSockets
)
