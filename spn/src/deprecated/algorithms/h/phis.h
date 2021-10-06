#pragma once

#include "../../../dlib/h/directedGraph.h"
#include "../../util/h/column.h"
#include "../../util/h/table.h"
#include <array>
#include <cmath>
#include <iostream>
#include <random>

// TODO (if all algorithms work properly) for algorithm 1: union find data structure, lib: c++ boost

std::vector<std::vector<std::vector<double>>> getPhis(Table d);