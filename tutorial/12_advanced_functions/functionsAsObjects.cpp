#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

using namespace std;

double multBy2(double num){
   return num * 2;
}

double doMath(function<double(double)> func, double num){
   return func(num);
}

double multBy3(double num){
   return num * 3;
}

int main() {
   auto times2 = multBy2;
   cout << "5 * 2 = " << times2(5) << "\n";
   cout << "6 * 2 = " << doMath(times2, 6) << "\n";
   cout << "7 * 2 = " << doMath(multBy2, 7) << "\n";

   vector<function<double(double)>> funcs(2);
   funcs[0] = multBy2;
   funcs[1] = multBy3;

   cout << "8 * 2 = " << funcs[0](8) << "\n";
   cout << "8 * 3 = " << funcs[1](8) << "\n";


   return 0;
}