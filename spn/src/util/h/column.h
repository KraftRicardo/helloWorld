#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <iostream>

const std::string NOT_SET = "not_set";

class Column {
   private:
   std::string name;
   std::vector<uint64_t> data;

   public:
   explicit Column(std::string newName = NOT_SET, std::vector<uint64_t> newData = std::vector<uint64_t>());

   void print();
   std::string getName();
   std::vector<uint64_t> getData();
};
