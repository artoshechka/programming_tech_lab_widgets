cmake_minimum_required(VERSION 3.16)

project(programming_tech_lab_widgets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(square_module)
add_subdirectory(counter_module)
add_subdirectory(figure_module)
add_subdirectory(launcher_module)

add_executable(programming_tech_lab_widgets main.cpp)
target_link_libraries(programming_tech_lab_widgets
	PRIVATE
		launcher_module
		Qt5::Widgets
)
