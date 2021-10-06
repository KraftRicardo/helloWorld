#include "../h/numberGenerator.h"

using namespace std;

double randDouble_uniform(double lowerBound, double upperBound) {
   return lowerBound + (double)(rand()) / ((double)(RAND_MAX/(upperBound - lowerBound)));
}


