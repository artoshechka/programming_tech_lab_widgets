add_library(figure_module
	Area.hpp
	Figure.hpp
	Window.hpp
	src/Area.cpp
	src/Figure.cpp
	src/Window.cpp
)

target_include_directories(figure_module
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(figure_module
	PUBLIC
		Qt5::Widgets
)
