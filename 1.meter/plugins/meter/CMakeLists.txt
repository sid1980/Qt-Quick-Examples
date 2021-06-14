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

set_target_properties(meter
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/meter
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/meter
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/meter
)

add_custom_command(TARGET meter POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/qmldir
	$<TARGET_FILE_DIR:meter>/qmldir 
		
	COMMAND qmlplugindump 
	plugins.meter 0.1 
	${CMAKE_BINARY_DIR} 
	> $<TARGET_FILE_DIR:meter>/meter.qmltypes
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	install(TARGETS meter DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/meter)
	install(FILES $<TARGET_FILE_DIR:meter>/qmldir DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/meter)
	install(FILES $<TARGET_FILE_DIR:meter>/meter.qmltypes DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins/meter)
endif()
