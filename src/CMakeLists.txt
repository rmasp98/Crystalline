add_subdirectory(window)
add_subdirectory(renderer)

# TODO: figure out if shared is appropriate
add_library(crystalline SHARED application.cpp)

# TODO: figure out if these need to be public
target_link_libraries(crystalline PUBLIC AsyncLib crystwindow crystrenderer)

target_compile_features(crystalline PRIVATE cxx_std_17)
target_compile_options(crystalline PRIVATE -Wall -Wextra -Werror -Wpedantic)

target_include_directories(crystalline
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        ${PROJECT_SOURCE_DIR}/src
)

