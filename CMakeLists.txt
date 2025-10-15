cmake_minimum_required(VERSION 3.15)
project(AlgoViewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-fdiagnostics-color=always -g)

set(SFML_ROOT "libs/SFML")
set(IMGUI_ROOT "libs/ImGui")
set(IMGUI_SFML_ROOT "libs/ImGui-SFML")

file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles")
file(GLOB IMGUI_SOURCES ${IMGUI_ROOT}/*.cpp)
file(GLOB IMGUI_SFML_SOURCES ${IMGUI_SFML_ROOT}/*.cpp)

add_executable(AlgoViewer
    ${SOURCES}
    ${IMGUI_SOURCES}
    ${IMGUI_SFML_SOURCES}
)

target_include_directories(AlgoViewer PRIVATE
    ${SFML_ROOT}/include
    ${IMGUI_ROOT}
    ${IMGUI_SFML_ROOT}
)

target_link_directories(AlgoViewer PRIVATE
    ${SFML_ROOT}/lib
)

target_link_libraries(AlgoViewer PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    opengl32
)
