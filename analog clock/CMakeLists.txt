cmake_minimum_required(VERSION 3.14)
project(analog_clock LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml Gui Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Qml Gui Core REQUIRED)

set(PROJECT_SOURCES
	./src/main.cpp
	./include/clock_backend.hpp
	./src/clock_backend.cpp
	./qml/qml.qrc
	./img/img.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(analog_clock ${PROJECT_SOURCES})
else()
	if(ANDROID)
		add_library(analog_clock SHARED ${PROJECT_SOURCES})
	else()
		add_executable(analog_clock ${PROJECT_SOURCES})
	endif()
endif()

add_custom_target(run
	COMMAND analog_clock
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_compile_definitions(analog_clock PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_include_directories(analog_clock PRIVATE ./include)
target_link_libraries(analog_clock PRIVATE 
	Qt${QT_VERSION_MAJOR}::Qml
	Qt${QT_VERSION_MAJOR}::Gui
	Qt${QT_VERSION_MAJOR}::Core
)

set_property(TARGET analog_clock PROPERTY CXX_STANDARD 20)

if(WIN32)
	set_property(TARGET analog_clock PROPERTY WIN32_EXECUTABLE true)
endif()
