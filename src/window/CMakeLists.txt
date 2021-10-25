add_library(crystwindow SHARED glfw/glfw_window.cpp)

target_link_libraries(crystwindow PUBLIC glfw AsyncLib)

target_compile_features(crystwindow PRIVATE cxx_std_17)
target_compile_options(crystwindow PRIVATE -Wall -Wextra -Werror -Wpedantic)

target_include_directories(crystwindow
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        ${PROJECT_SOURCE_DIR}/src
)

