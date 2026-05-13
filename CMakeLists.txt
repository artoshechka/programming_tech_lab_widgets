cmake_minimum_required(VERSION 3.16)

project(programming_tech_lab_widgets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_subdirectory(square_module)

add_executable(programming_tech_lab_widgets main.cpp)
target_link_libraries(programming_tech_lab_widgets
	PRIVATE
		square_module
		Qt${QT_VERSION_MAJOR}::Widgets
)
