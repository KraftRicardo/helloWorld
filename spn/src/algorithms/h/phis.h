#pragma once

#include "../../util/h/table.h"
#include "../../util/h/column.h"
#include "../../util/h/directedGraph.h"
#include <iostream>
#include <random>
#include <cmath>
#include <array>

// TODO (if all algorithms work properly) for algorithm 1: union find data structure, lib: c++ boost

std::vector<std::vector<std::vector<double>>> getPhis(Table d);