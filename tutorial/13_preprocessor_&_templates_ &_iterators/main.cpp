#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include "Animal.h"
#include <iterator>

using namespace std;

int main() {
   Animal spot = Animal();
   spot.name = "Spot";
   cout << "The animal is named " << spot.name << "\n";

   return 0;
}
