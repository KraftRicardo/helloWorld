#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <iostream>
#include <filesystem>
#include "column.h"
#include <dlib/matrix.h>

class Table {
   private:
   std::string name;
   std::string path;
   std::vector<Column> columns;

   public:
   explicit Table(std::string newPath = NOT_SET, std::vector<Column> newColumns = std::vector<Column>());

   uint64_t getNumberOfColumns();
   uint64_t getNumberOfRows();
   void print();
   dlib::matrix<double> getMatrix();

   // Getter
   std::string getName();
   std::string getPath();
   std::vector<Column> getColumns();
};

Table csvToTable();
