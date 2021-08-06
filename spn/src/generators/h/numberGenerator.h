#pragma once

#include <vector>
#include <cassert>
#include <iostream>
#include <random>

std::vector<int> generateRandomVector(int lowerBorder, int upperBorder, u_int64_t length);
int generateRandomNumber(int lowerBorder, int upperBorder);
void setSeed(uint seed);
void setRandomSeed();
int generateRandomNumber2(int lowerBorder, int upperBorder);