cmake_minimum_required(VERSION 3.5)

project(ScratchLink LANGUAGES CXX VERSION 1.3.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS WebSockets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

configure_file(src/Config.h.in ${CMAKE_BINARY_DIR}/generated/Config.h)
include_directories(${CMAKE_BINARY_DIR}/generated/)

add_executable(
        ScratchLink
        res.qrc
        src/controller/ScratchLinkController.cpp
        src/controller/ScratchLinkController.h
        src/main.cpp
        src/model/ScratchLinkApplication.cpp
        src/model/ScratchLinkApplication.h
        src/model/ScratchLinkBluetoothClient.cpp
        src/model/ScratchLinkBluetoothClient.h
        src/model/ScratchLinkProtocolVersion.cpp
        src/model/ScratchLinkProtocolVersion.h
        src/model/ScratchLinkWebSocketServer.cpp
        src/model/ScratchLinkWebSocketServer.h
        src/view/ScratchLinkTrayIcon.cpp
        src/view/ScratchLinkTrayIcon.h
        src/view/ScratchLinkTrayIconMenu.cpp
        src/view/ScratchLinkTrayIconMenu.h
        src/view/ScratchLinkView.cpp
        src/view/ScratchLinkView.h
)

target_link_libraries(ScratchLink PRIVATE Qt5::Widgets Qt5::WebSockets Qt5::Core)
