#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void assignAge(int* pAge){
   *pAge = 22;
}

int main(){
   int age = 43;

   assignAge(&age);
   cout << "Pointer age = " << age << "\n";

   return 0;
}