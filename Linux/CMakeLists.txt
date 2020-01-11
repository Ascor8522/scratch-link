cmake_minimum_required(VERSION 3.5)

project(ScratchLink LANGUAGES CXX VERSION 1.3.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

configure_file(src/Config.h.in ${CMAKE_BINARY_DIR}/generated/Config.h)
include_directories(${CMAKE_BINARY_DIR}/generated/)

add_executable(
        ScratchLink
        res.qrc
        src/main.cpp
        src/controller/ScratchLinkController.cpp
        src/controller/ScratchLinkController.h
        src/model/ScratchLinkApplication.cpp
        src/model/ScratchLinkApplication.h
        src/view/ScratchLinkView.cpp
        src/view/ScratchLinkView.h
        src/view/ScratchLinkTrayIcon.cpp
        src/view/ScratchLinkTrayIcon.h
        src/view/ScratchLinkTrayIconMenu.cpp
        src/view/ScratchLinkTrayIconMenu.h
)

target_link_libraries(ScratchLink PRIVATE Qt5::Widgets)
