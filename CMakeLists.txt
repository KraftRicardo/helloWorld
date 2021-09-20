cmake_minimum_required(VERSION 3.19)

# set the project name
project(helloWorld VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

# add compile options
#add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor -Werror)
add_compile_options(-fsanitize=address -g -Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor)
add_link_options(-fsanitize=address)

# project
add_executable(spn_main
        spn/src/main/cpp/main.cpp
        spn/src/algorithms/cpp/phis.cpp
        spn/src/algorithms/cpp/clusterSamplesRDC.cpp
        spn/src/algorithms/cpp/splitFeaturesRDC.cpp
        spn/src/algorithms/cpp/learnMSPN.cpp
        spn/src/algorithms/cpp/kmeans.cpp
        spn/src/generators/cpp/numberGenerator.cpp
        spn/src/generators/cpp/tableGenerator.cpp
        spn/src/generators/cpp/eigen.cpp
        spn/src/persistence/cpp/csvImporter.cpp
        spn/src/util/cpp/table.cpp
        spn/src/util/cpp/column.cpp
        spn/src/util/cpp/directedGraph.cpp
        spn/src/util/cpp/util.cpp
        spn/src/util/cpp/point.cpp
        )

add_executable(spn_normal spn/src/test/cpp/testNormal.cpp)


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

add_executable(12_adv_fun tutorial/12_advanced_functions/functionsAsObjects.cpp)
add_executable(12_adv_fun2 tutorial/12_advanced_functions/functionsAsObjects2.cpp)
add_executable(12_adv_fun3 tutorial/12_advanced_functions/functionsAsObjects3.cpp)

add_executable(13_temps "tutorial/13_preprocessor_&_templates_ &_iterators/main.cpp" "tutorial/13_preprocessor_&_templates_ &_iterators/Animal.h" "tutorial/13_preprocessor_&_templates_ &_iterators/Animal.cpp")
add_executable(13_temps2 "tutorial/13_preprocessor_&_templates_ &_iterators/preprocessor.cpp")
add_executable(13_temps3 "tutorial/13_preprocessor_&_templates_ &_iterators/templates.cpp")
add_executable(13_temps4 "tutorial/13_preprocessor_&_templates_ &_iterators/templates2.cpp")
add_executable(13_temps5 "tutorial/13_preprocessor_&_templates_ &_iterators/iterators.cpp")

add_executable(14_sPointer tutorial/14_smart_pointers_&_polymorphic_templates/memory.cpp)
add_executable(14_sPointer2 tutorial/14_smart_pointers_&_polymorphic_templates/memory2.cpp)
add_executable(14_sPointer3 tutorial/14_smart_pointers_&_polymorphic_templates/polymorphicTemplates.cpp)

add_executable(15_threads tutorial/15_threads/threads.cpp)
add_executable(15_threads_2 tutorial/15_threads/threads2.cpp)
add_executable(15_threads_3 tutorial/15_threads/threads3.cpp)
add_executable(15_threads_4 tutorial/15_threads/threads4.cpp)

add_executable(16_containers tutorial/16_sequence_containers/deque.cpp)
add_executable(16_containers2 tutorial/16_sequence_containers/list.cpp)
add_executable(16_containers3 tutorial/16_sequence_containers/forwardList.cpp)

add_executable(17_moreContainers tutorial/17_associate_containers_enums_adapters/set.cpp)
add_executable(17_moreContainers2 tutorial/17_associate_containers_enums_adapters/multiset.cpp)
add_executable(17_moreContainers3 tutorial/17_associate_containers_enums_adapters/map.cpp)
add_executable(17_moreContainers4 tutorial/17_associate_containers_enums_adapters/multimap.cpp)
add_executable(17_moreContainers5 tutorial/17_associate_containers_enums_adapters/stack.cpp)
add_executable(17_moreContainers6 tutorial/17_associate_containers_enums_adapters/queue.cpp)
add_executable(17_moreContainers7 tutorial/17_associate_containers_enums_adapters/priorityQueue.cpp)
add_executable(17_moreContainers8 tutorial/17_associate_containers_enums_adapters/enum.cpp)

add_executable(18_regex tutorial/18_regular_expressions/basics.cpp)
add_executable(18_regex2 tutorial/18_regular_expressions/basics2.cpp)
add_executable(18_regex3 tutorial/18_regular_expressions/basics3.cpp)
add_executable(18_regex4 tutorial/18_regular_expressions/problem.cpp)

add_executable(19_regexII tutorial/19_regex_II/basics4.cpp)

add_executable(20_regexIII tutorial/20_regex_III/basics5.cpp)


