#include <cmath>
#include <iostream>

using namespace std;

int main() {
   cout << "abs(-10) = " << abs(-10) << "\n";
   cout << "max(5,4) = " << max(5, 4) << "\n";
   cout << "min(5,4) = " << min(5, 4) << "\n";
   cout << "fmax(5.3,4.3) = " << fmax(5.3, 4.3) << "\n";
   cout << "fmin(5.3,4.3) = " << fmin(5.3, 4.3) << "\n";

   // e ^ x
   cout << "exp(1) = " << exp(1) << "\n";

   // 2 ^ x
   cout << "exp2(1) = " << exp2(1) << "\n";

   // e * e * e ~= 20 so log(20.079) ~= 3
   cout << "log(20.079) = " << log(20.079) << "\n";

   // 10 * 10 * 10 = 1000, so log10(1000) = 3
   cout << "log10(1000) = " << log10(1000) << "\n";

   // 2 * 2 * 2 = 8
   cout << "log2(8) = " << log2(8) << "\n";

   // 2 ^ 3
   cout << "pow(2,3) = " << pow(2, 3) << "\n";

   // Returns what times itself equals the provided value
   cout << "sqrt(100) = " << sqrt(100) << "\n";

   // What cubed equals the provided
   cout << "cbrt(1000) = " << cbrt(1000) << "\n";

   // Hypotenuse : SQRT(A^2 + B^2)
   cout << "hypot(2,3) = " << hypot(2, 3) << "\n";
   cout << "ceil(10.45) = " << ceil(10.45) << "\n";
   cout << "floor(10.45) = " << floor(10.45) << "\n";
   cout << "round(10.45) = " << round(10.45) << "\n";

   // Also sin, cos, tan, asin, acos, atan, atan2,
   // sinh, cosh, tanh, asinh, acosh, atanh

   return 0;
}