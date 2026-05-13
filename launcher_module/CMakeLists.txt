add_library(launcher_module
    launcher.hpp
    src/launcher.cpp
)

target_include_directories(launcher_module
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(launcher_module
    PUBLIC
        square_module
        counter_module
        figure_module
        Qt5::Widgets
)
