#pragma once

#include "directedGraph.h"
#include <vector>
#include <dlib/matrix.h>
#include <dlib/statistics/cca.h>

void printConnectedComponents(std::vector<dlib::matrix<double>> matrices, double alpha);
void testCCA();