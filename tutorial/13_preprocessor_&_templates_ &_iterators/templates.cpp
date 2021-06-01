#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
void times2(T val) {
   cout << val << " * 2 = " << val * 2 << "\n";
}

template <typename T>
T add(T val, T val2) {
   return val + val2;
}

template <typename T>
T max(T val, T val2) {
   return val > val2 ? val : val2;
}

int main() {
   times2(5);
   times2(5.3);
   times2(5.3f);

   cout << "5 + 4 = " << add(5, 4) << "\n";
   cout << "5.5 + 4.4 = " << add(5.5, 4.4) << "\n";
   cout << "max 4 or 8 = " << ::max(4, 8) << "\n";
   cout << "max A or B = " << ::max('A', 'B') << "\n";
   // TODO In the tutorial Cat is the max? Important difference?
   cout << "max Dog or Cat = " << ::max("Dog", "Cat") << "\n";

   return 0;
}
