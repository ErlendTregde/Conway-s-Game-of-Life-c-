cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "../SFML/SFML-2.6.2/lib/cmake/SFML")


include_directories(${SFML_ROOT}/include)
link_directories(${SFML_ROOT}/lib)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(GameOfLife src/main.cpp
        include/Grid.h
        src/Grid.cpp
        include/Renderer.h
        src/Renderer.cpp
        include/Game.h
        src/Game.cpp)

target_link_libraries(GameOfLife sfml-system sfml-window sfml-graphics)
