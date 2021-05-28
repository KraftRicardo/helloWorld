#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
   int age = 43;
   int* pAge = NULL;

   pAge = &age;

   cout << "Address : " << pAge << "\n";
   cout << "Value at address : " << *pAge << "\n";

   int arr[] = {1, 2, 3, 4};
   int* pArr = arr;

   cout << "1st " << *pArr << " address " << pArr << "\n";
   pArr++;
   cout << "2nd " << *pArr << " address " << pArr << "\n";
   pArr--;
   cout << "1st " << *pArr << " address " << pArr << "\n";

   return 0;
}