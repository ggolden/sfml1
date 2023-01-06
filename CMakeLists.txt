cmake_minimum_required(VERSION 3.24)
project(sfml1)

set(CMAKE_CXX_STANDARD 17)

# add_executable(sfml1 main.cpp)

set(SOURCE_FILES main.cpp)
add_executable(sfml1 ${SOURCE_FILES})

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(sfml1 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
