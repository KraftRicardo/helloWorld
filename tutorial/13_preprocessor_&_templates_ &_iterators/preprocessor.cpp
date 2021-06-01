#include <iostream>
#include <cmath>

#define PI 3.14159
#define AREA_CIRCLE(radius) (PI * (pow(radius, 2)))

using namespace std;

int main() {
   cout << "Circle area : " << AREA_CIRCLE(5) << "\n";

   return 0;
}
