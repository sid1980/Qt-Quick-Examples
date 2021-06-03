cmake_minimum_required(VERSION 2.8.12)
project(analog_clock LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml Quick Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Qml Quick Core REQUIRED)

add_library(analog_clock SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/clock_backend.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/clock_backend.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/plugin.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/plugin.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/img/img.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/qml/qml.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
)

target_link_libraries(analog_clock PRIVATE 
	Qt${QT_VERSION_MAJOR}::Qml
	Qt${QT_VERSION_MAJOR}::Quick
	Qt${QT_VERSION_MAJOR}::Core
)

target_include_directories(analog_clock PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET analog_clock PROPERTY AUTOMOC ON)
set_property(TARGET analog_clock PROPERTY AUTORCC ON)
set_property(TARGET analog_clock PROPERTY CXX_STANDARD 20)

add_custom_command(TARGET analog_clock POST_BUILD COMMAND
	${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
	$<TARGET_FILE_DIR:analog_clock>/qmldir
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	install(TARGETS analog_clock DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/analog_clock)
	install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/qmldir DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/analog_clock)
endif()
