#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <iostream>
#include "column.h"

class Table {
   private:
   std::string name;
   std::vector<Column> columns;

   public:
   explicit Table(std::string newName = NOT_SET, std::vector<Column> newColumns = std::vector<Column>());

   uint64_t numberOfRows();
   void print();
};
