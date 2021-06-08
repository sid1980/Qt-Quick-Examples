cmake_minimum_required(VERSION 2.8.12)
project(wave_background LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml Quick Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Qml Quick Core REQUIRED)

add_library(wave_background SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/plugin.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/plugin.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/qml/qml.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
	${CMAKE_CURRENT_SOURCE_DIR}/wave_background.qmltypes
)

target_link_libraries(wave_background PRIVATE 
	Qt${QT_VERSION_MAJOR}::Qml
	Qt${QT_VERSION_MAJOR}::Quick
	Qt${QT_VERSION_MAJOR}::Core
)

target_include_directories(wave_background PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET wave_background PROPERTY AUTOMOC ON)
set_property(TARGET wave_background PROPERTY AUTORCC ON)
set_property(TARGET wave_background PROPERTY CXX_STANDARD 20)

add_custom_command(TARGET wave_background POST_BUILD COMMAND
	${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
	$<TARGET_FILE_DIR:wave_background>/qmldir
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	install(TARGETS wave_background DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/wave_background)
	install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/qmldir DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/wave_background)
	install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/wave_background.qmltypes DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/wave_background)
endif()
