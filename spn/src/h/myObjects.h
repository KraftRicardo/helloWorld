#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

static const char* const NOT_SET = "not set";

struct Column {
   std::string name;
   std::vector<uint64_t> data;

   Column(std::string name = NOT_SET, std::vector<uint64_t> data = std::vector<uint64_t>()) : name(name), data(data) {}
};

struct Table {
   std::string name;
   std::vector<Column> columns;

   Table(std::string name = NOT_SET, std::vector<Column> columns = std::vector<Column>()) : name(name), columns(columns) {}
};

// Node
//  Product Node
//  Sum Node
//  Leaf Node
