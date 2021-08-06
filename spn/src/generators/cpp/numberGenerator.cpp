#include "../h/numberGenerator.h"

using namespace std;

vector<int> generateRandomVector(int lowerBorder, int upperBorder, u_int64_t length){
   vector<int> result = vector<int>();

   assert(lowerBorder < upperBorder);

   for(u_int64_t i = 0; i < length; i++){
      result.push_back(generateRandomNumber(lowerBorder, upperBorder));
   }

   return result;
}

// seed typically 1, unless set manually
int generateRandomNumber(int lowerBorder, int upperBorder) {
   return lowerBorder + ( std::rand() % ( upperBorder - lowerBorder + 1 ));
}

void setSeed(uint seed){
   cout << "Using seed: " << seed;
   srand(seed);
}

void setRandomSeed(){
   setSeed(static_cast<uint>(time(nullptr)));
}

int generateRandomNumber2(int lowerBorder, int upperBorder){
   random_device rd; // obtain a random number from hardware
   mt19937 gen(rd()); // seed the generator
   uniform_int_distribution<> distr(lowerBorder, upperBorder); // define the range

   return distr(gen);
}