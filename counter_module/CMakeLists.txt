add_library(counter_module
	counter.hpp
	src/counter.cpp
)

target_include_directories(counter_module
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(counter_module
	PUBLIC
		Qt5::Widgets
)
