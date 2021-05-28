cmake_minimum_required(VERSION 3.19)

# set the project name
project(helloWorld VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

# add compile options
add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor -Werror)
add_link_options(-fsanitize=address)

# add the executable
add_executable(main cpp/main.cpp cpp/helper.cpp cpp/helper2.cpp hpp/vl4.h cpp/vl4.cpp)
add_executable(testIO cpp/sayhello.cpp cpp/saybye.cpp cpp/print_greetings.cpp cpp/helper2.cpp cpp/vl4.cpp)
add_executable(main4 cpp/main4.cpp)
add_executable(main5 cpp/main5.cpp)
add_executable(hekaton cpp/hekaton.cpp)

# lecture
add_executable(lecture lecture/lvalues.cpp)
add_executable(lecture_2 lecture/autoUseCase.cpp)

# tutorial
add_executable(00_basics tutorial/0_basics/passArgs.cpp)
add_executable(00_basics_2 tutorial/0_basics/dataTypeSize.cpp)
add_executable(00_basics_3 tutorial/0_basics/inputOutput.cpp)

add_executable(01_containers tutorial/1_containers/arraysAndVectors.cpp)

add_executable(02_pointers tutorial/2_pointers/pointer.cpp)
add_executable(02_pointers_2 tutorial/2_pointers/pointerAndFunction.cpp)
add_executable(02_pointers_3 tutorial/2_pointers/pointerAndArray.cpp)
add_executable(02_pointers_4 tutorial/2_pointers/problem.cpp)
add_executable(02_pointers_5 tutorial/2_pointers/problem2.cpp)

add_executable(03_exceptions tutorial/3_exceptions/problem1.cpp)
add_executable(03_exceptions_2 tutorial/3_exceptions/exception.cpp)

add_executable(04_strings tutorial/4_strings/string.cpp)
add_executable(04_strings_2 tutorial/4_strings/problem.cpp)
add_executable(04_strings_3 tutorial/4_strings/mathFunctions.cpp)

add_executable(05_problems tutorial/5_problems/problems.cpp)
add_executable(05_problems_2 tutorial/5_problems/problems2.cpp)

add_executable(06_problems_3 tutorial/6_problems/problems3.cpp)
add_executable(06_problems_4 tutorial/6_problems/problems4.cpp)

add_executable(07_rec tutorial/7_recursion_&_overload/recursion.cpp)
add_executable(07_rec_2 tutorial/7_recursion_&_overload/overload.cpp)

add_executable(08_lambdas tutorial/8_lambdas/lambda.cpp)
add_executable(08_lambdas_2 tutorial/8_lambdas/ternary_operator.cpp)

add_executable(09_obj tutorial/9_objects/animals.cpp)
add_executable(09_obj_2 tutorial/9_objects/warriors.cpp)

add_executable(10_poly tutorial/10_polymorphism/structs.cpp)
add_executable(10_poly_2 tutorial/10_polymorphism/friends.cpp)
add_executable(10_poly_3 tutorial/10_polymorphism/poly.cpp)

add_executable(11_op tutorial/11_operator_&_file_IO/operators.cpp)
add_executable(11_op_2 tutorial/11_operator_&_file_IO/io.cpp)
add_executable(11_op_3 tutorial/11_operator_&_file_IO/io2.cpp)

add_executable(threads tutorial/threads/threads.cpp)
add_executable(threads_2 tutorial/threads/threads2.cpp)
add_executable(threads_3 tutorial/threads/threads3.cpp)
add_executable(threads_4 tutorial/threads/threads4.cpp)