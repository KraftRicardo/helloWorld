#include <iostream>

using namespace std;

int fib(int i){
   if(i <= 2){
      return i;
   } else {
      return fib(i-1) + fib(i-2);
   }
}

int main() {
   cout << "Fib 4 = " << fib(4) << "\n";
   cout << "Fib 5 = " << fib(5) << "\n";
   cout << "Fib 6 = " << fib(6) << "\n";

   return 0;
}


