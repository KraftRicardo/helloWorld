#pragma once

#include "vector"
#include "string"
#include "numberGenerator.h"
#include "../../h/csvImporter.h"

void generateTable(std::string saveFileName);
void generateTable(std::string saveFileName, uint64_t numberOfColumns, uint64_t columnSize, std::vector<std::string> names, std::vector<int> minRanges, std::vector<int> maxRanges);