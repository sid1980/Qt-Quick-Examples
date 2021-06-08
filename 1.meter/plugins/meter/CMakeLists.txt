cmake_minimum_required(VERSION 2.8.12)
project(meter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml Quick Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Qml Quick Core REQUIRED)

add_library(meter SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/nidle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/nidle.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/scale.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/scale.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/plugin.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/plugin.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/qml/qml.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
	${CMAKE_CURRENT_SOURCE_DIR}/meter.qmltypes
)

target_link_libraries(meter PRIVATE 
	Qt${QT_VERSION_MAJOR}::Qml
	Qt${QT_VERSION_MAJOR}::Quick
	Qt${QT_VERSION_MAJOR}::Core
)

target_include_directories(meter PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET meter PROPERTY AUTOMOC ON)
set_property(TARGET meter PROPERTY AUTORCC ON)
set_property(TARGET meter PROPERTY CXX_STANDARD 20)

add_custom_command(TARGET meter POST_BUILD COMMAND
	${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
	$<TARGET_FILE_DIR:meter>/qmldir
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	install(TARGETS meter DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/meter)
	install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/qmldir DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/meter)
	install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/meter.qmltypes DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/meter)
endif()
