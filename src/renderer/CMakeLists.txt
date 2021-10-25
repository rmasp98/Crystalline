add_library(crystrenderer SHARED vulkan/vulkan_render_api.cpp)

target_link_libraries(crystrenderer PUBLIC AsyncLib Vulkan-Headers)

target_compile_features(crystrenderer PRIVATE cxx_std_17)
target_compile_options(crystrenderer PRIVATE -Wall -Wextra -Werror -Wpedantic)

target_include_directories(crystrenderer
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        ${PROJECT_SOURCE_DIR}/src
)

