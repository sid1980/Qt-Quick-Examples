cmake_minimum_required(VERSION 3.14)
project(a.out LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Qml Gui REQUIRED)

add_subdirectory(./plugins)

set(PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/qml/qml.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(a.out ${PROJECT_SOURCES})
else()
	if(ANDROID)
		add_library(a.out SHARED ${PROJECT_SOURCES})
	else()
		add_executable(a.out ${PROJECT_SOURCES})
	endif()
endif()

add_custom_target(run
	COMMAND a.out
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(a.out PRIVATE 
	Qt${QT_VERSION_MAJOR}::Qml
	Qt${QT_VERSION_MAJOR}::Gui
	meter
)

set_property(TARGET a.out PROPERTY AUTOMOC ON)
set_property(TARGET a.out PROPERTY AUTORCC ON)
set_property(TARGET a.out PROPERTY CXX_STANDARD 20)

if(WIN32)
	set_property(TARGET a.out PROPERTY WIN32_EXECUTABLE true)
endif()
