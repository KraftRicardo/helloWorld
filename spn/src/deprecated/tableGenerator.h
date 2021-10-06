#pragma once

#include "../../persistence/h/csvImporter.h"
#include "../generators/h/numberGenerator.h"
#include "string"
#include "vector"

void generateTable(std::string saveFileName);
void generateTable(std::string saveFileName, uint64_t numberOfColumns, uint64_t columnSize, std::vector<std::string> names, std::vector<int> minRanges, std::vector<int> maxRanges);