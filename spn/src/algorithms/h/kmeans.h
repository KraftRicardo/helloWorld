#pragma once
// source: https://reasonabledeviations.com/2019/10/02/k-means-in-cpp/

#include "../../util/h/point.h"

#include <iostream>
#include <ctime>     // for a random seed
#include <fstream>   // for file-reading
#include <iostream>  // for file-reading
#include <sstream>   // for file-reading
#include <vector>
#include <string>
#include <cstring>

void KMeans();
static std::vector<Point> readMall();