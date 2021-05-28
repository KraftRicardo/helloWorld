#include <iostream>
#include <utility>

using namespace std;

struct Foo {
   Foo(float y, long z) : y(y), z(z) {}
   float y;
   long z;
};

std::pair<int, long> bar();

int main() {
   Foo foo(2.06f, 40l);
   int array[] = {1, 2, 3, 4};
   auto [a1, a2, a3, a4] = array; // copies array, a1 - a4 refer to copy
   auto& [y, z] = foo; // y refers to foo.y, z refers to foo.z
//   auto [l, r] = bar(); // move-constructs pair p, l refers to p.first, r refers to p.second

   cout << a1 << "\n";
   cout << a2 << "\n";
   cout << a3 << "\n";
   cout << a4 << "\n";
   cout << y << "\n";
   cout << z << "\n";
//   cout << l << "\n";
//   cout << r << "\n";

}
