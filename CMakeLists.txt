cmake_minimum_required(VERSION 3.15)
project(AlgoViewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-fdiagnostics-color=always -g)

set(BUILD_SHARED_LIBS OFF)
add_definitions(-DSFML_STATIC)

set(SFML_ROOT "libs/SFML")
set(IMGUI_ROOT "libs/ImGui")
set(IMGUI_SFML_ROOT "libs/ImGui-SFML")
set(SRC_ROOT "src")

file(GLOB_RECURSE SOURCES "${SRC_ROOT}/*.cpp")
file(GLOB IMGUI_SOURCES ${IMGUI_ROOT}/*.cpp)
file(GLOB IMGUI_SFML_SOURCES ${IMGUI_SFML_ROOT}/*.cpp)

add_executable(AlgoViewer
    ${SOURCES}
    ${IMGUI_SOURCES}
    ${IMGUI_SFML_SOURCES}
)

set_target_properties(AlgoViewer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_include_directories(AlgoViewer PRIVATE
    ${SFML_ROOT}/include
    ${IMGUI_ROOT}
    ${IMGUI_SFML_ROOT}
    ${SRC_ROOT}
)

target_link_directories(AlgoViewer PRIVATE
    ${SFML_ROOT}/lib
)

target_link_options(AlgoViewer PRIVATE -mconsole -static -static-libgcc -static -static-libstdc++)

target_link_libraries(AlgoViewer PRIVATE
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
    opengl32
    freetype
    winmm
    gdi32
    ws2_32
)
