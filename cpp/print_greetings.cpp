#include <iostream>
#include "../hpp/sayhello.hpp"
#include "../hpp/saybye.hpp"

const char* INPUT = "Ricardo";

int main(int argc, const char** argv) {
//    if (argc != 2) {
//        std::cerr << "Please write: ./print_greetings name" << std::endl;
//        return 1;
//    }

    sayhello(INPUT);
    saybye(INPUT);
    return 0;
}

