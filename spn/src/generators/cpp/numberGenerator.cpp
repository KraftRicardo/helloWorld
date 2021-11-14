#include "../h/numberGenerator.h"

#include <random>

using namespace std;

//use instead std::random

// WARNING: rand() + srand() is only pseudo random
// call: std::srand(std::time(nullptr)); before
double randomDouble_uniform(double lowerBound, double upperBound) {
   return lowerBound + (double)(rand()) / ((double)(RAND_MAX/(upperBound - lowerBound)));
}

// call: std::srand(std::time(nullptr)); before
int randomInt_uniform(int lowerBound, int upperBound){
   return lowerBound + ((int) rand() % (upperBound - lowerBound));
//   std::uniform_int_distribution() // TODO use this instead
}


