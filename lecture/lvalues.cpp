#include <iostream>

using namespace std;

int global = 100;

int& getGlobal(){
   return global;
}

int getGlobal2(){
   return global;
}

int main() {
   cout << global << "\n";

   int a = getGlobal();
   a = 5;
   cout << "a : " << a << "\n";
   cout << global << "\n";

   int b = getGlobal2();
   b = 6;
   cout << "b : " << b << "\n";
   cout << global << "\n";

   int* c = &getGlobal();
   *c = 7;
   cout << "*c : " << *c << "\n";
   cout << global << "\n";

//   int* d = &getGlobal2();
//   *d = 7;
//   cout << "*d : " << *d << "\n";
//   cout << global << "\n";

   getGlobal() = 20;
   cout << global << "\n";

   return 0;
}

