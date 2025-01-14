cmake_minimum_required(VERSION 3.16)

project(qrc-demo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

set(CMAKE_AUTORCC ON)

qt_add_executable(qrc-demo
    main_qrc.cpp
    resources.qrc
)

target_link_libraries(qrc-demo PRIVATE Qt6::Core)
