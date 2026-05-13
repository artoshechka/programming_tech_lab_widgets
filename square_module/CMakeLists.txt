add_library(square_module
	square_module.hpp
	src/square_module.cpp
)

target_include_directories(square_module
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(square_module
	PUBLIC
		Qt5::Widgets
)
