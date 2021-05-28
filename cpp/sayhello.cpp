#include "../hpp/sayhello.hpp"
#include <iostream>

/// Print a greeting for `name`
void sayhello(const std::string& name) {
    std::cout << "Hello " << name << '!' << std::endl;
}
