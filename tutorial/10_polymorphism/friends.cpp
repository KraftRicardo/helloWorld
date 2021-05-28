#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class A {
   int a;
   friend class B;
   friend void foo(A&);
};
class B {
   friend class C;
   void foo(A& a) {
      a.a = 42; // OK
   }
};
class C {
   void foo(A& a) {
      a.a = 42; // ERROR
   }
};
void foo(A& a) {
   a.a = 42; // OK
}

// ######################################################

class Customer {
   private:
   friend class GetCustomerData;
   string name;

   public:
   Customer(string name) : name(name) {}
};

class GetCustomerData {
   public:
   static string getName(Customer& customer) {
      return customer.name;
   }
};

int main() {
   Customer tom("Tom");
   //   GetCustomerData getName;
   cout << "Name : " << GetCustomerData::getName(tom) << "\n";

   return 0;
}