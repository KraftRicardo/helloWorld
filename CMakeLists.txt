cmake_minimum_required(VERSION 3.19)

project(helloWorld VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

# add compile options
#add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor -Werror)
#add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor -Werror=return-type)
add_compile_options(-O3)

#add_link_options(-fsanitize=address)

# subdirectories
find_package(dlib REQUIRED)

# project
add_executable(
        main-algorithm
        spn/src/algorithms/cpp/mainAlgorithm.cpp
        spn/src/util/cpp/dlibTable.cpp
        spn/src/algorithms/cpp/phis.cpp
        spn/src/algorithms/cpp/alg1.cpp
        spn/src/util/cpp/directedGraph.cpp
        spn/src/util/cpp/util.cpp
)
target_link_libraries(main-algorithm dlib)

add_executable(
        main-generator
        spn/src/generators/cpp/mainGenerator.cpp
        spn/src/generators/cpp/numberGenerator.cpp
        spn/src/util/cpp/dlibTable.cpp
        spn/src/util/cpp/util.cpp
)
target_link_libraries(main-generator dlib)

add_executable(
        main-kmeans
        spn/src/algorithms/cpp/kmeans.cpp
        spn/src/util/cpp/point.cpp
)