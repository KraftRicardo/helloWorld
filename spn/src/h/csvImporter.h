#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

static const char* const ONE_COLUMN = "../spn/res/ones.csv";
static const char* const THREE_COLUMNS = "../spn/res/three columns.csv";
static const char* const OUTPUT_ONES = "../spn/res/ones_copy.csv";
static const char* const OUTPUT_THREE = "../spn/res/three_cols_copy.csv";

int testCsvImporter();
void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<int>>> dataset);
std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename);