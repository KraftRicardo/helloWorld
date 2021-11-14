#pragma once

#include <dlib/matrix.h>
#include <filesystem>
#include <unistd.h>

void saveMatrixAsCsv(dlib::matrix<double> m, std::string filename);
void pwd();
