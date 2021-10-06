cmake_minimum_required(VERSION 3.19)

project(helloWorld VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

# add compile options
#add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor -Werror)
add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor)
add_link_options(-fsanitize=address)

# subdirectories
add_subdirectory(dlib-19.22/dlib dlib_build)

# project
add_executable(
        main-generator
        spn/src/generators/cpp/mainGen.cpp
        spn/src/generators/cpp/numberGenerator.cpp
        spn/src/algorithms/cpp/dlibTable.cpp
        spn/src/algorithms/cpp/util.cpp
)
target_link_libraries(main-generator dlib::dlib)

add_executable(
        main-dlib
        spn/src/algorithms/cpp/mainAlg.cpp
        spn/src/algorithms/cpp/dlibTable.cpp
        spn/src/algorithms/cpp/phis.cpp
        spn/src/algorithms/cpp/alg1.cpp
        spn/src/algorithms/cpp/directedGraph.cpp
        spn/src/algorithms/cpp/util.cpp
)
target_link_libraries(main-dlib dlib::dlib)