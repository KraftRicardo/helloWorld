#include <iostream>
#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>

using namespace std;

int main() {
   cout << "Min bool " << numeric_limits<bool>::min() << "\n";
   cout << "Max bool " << numeric_limits<bool>::max() << "\n";

   cout << "Min unsigned short int " << numeric_limits<uint16_t>::min() << "\n";
   cout << "Max unsigned short int " << numeric_limits<uint16_t>::max() << "\n";

   cout << "Min short int " << numeric_limits<int16_t>::min() << "\n";
   cout << "Max short int " << numeric_limits<int16_t>::max() << "\n";

   cout << "Min int " << numeric_limits<int>::min() << "\n";
   cout << "Max int " << numeric_limits<int>::max() << "\n";

   cout << "Min long " << numeric_limits<int64_t>::min() << "\n";
   cout << "Max long " << numeric_limits<int64_t>::max() << "\n";

   cout << "Min float " << numeric_limits<float>::min() << "\n";
   cout << "Max float " << numeric_limits<float>::max() << "\n";

   cout << "Min long double " << numeric_limits<long double>::min() << "\n";
   cout << "Max long double " << numeric_limits<long double>::max() << "\n";

   // Get the number of bytes used by a type
   std::cout << "bool Size " << sizeof(bool) << "\n";
   std::cout << "unsigned short int Size " << sizeof(uint16_t) << "\n";
   std::cout << "short int Size " << sizeof(int16_t) << "\n";
   std::cout << "int Size " << sizeof(int) << "\n";
   std::cout << "long int Size " << sizeof(int64_t) << "\n";
   std::cout << "float Size " << sizeof(float) << "\n";
   std::cout << "double Size " << sizeof(double) << "\n";
   std::cout << "long double Size " << sizeof(long double) << "\n";

   // More about printf()
   // char, int, 5 space right justified int,
   // 3 decimal float / double, string specifiers
   printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi");


//   fmt::print("Hello, world!\n");
//   std::string s = fmt::format("The answer is {}.", 42);
//   std::string s2 = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
//   std::vector<int> v = {1, 2, 3};
//   fmt::print("{}\n", v);

}