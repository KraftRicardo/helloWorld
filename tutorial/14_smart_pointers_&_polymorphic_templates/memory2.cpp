#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include <memory>
#include <stdio.h>

using namespace std;

int main() {

   int amtToStore;
   std::cout << "How many numbers do you want to store : ";
   std::cin >> amtToStore;

   // use unique pointers
   unique_ptr<int[]> pNums(new int[static_cast<unsigned long>(amtToStore)]);

   if(pNums != NULL){
      int i = 0;
      while(i < amtToStore){
         cout << "Enter a Number : ";
         // TODO size_t cast? Why and is it bad if I ignore this?
         cin >> pNums[static_cast<size_t>(i)];
         i++;
      }
   }

   cout << "You entered these numbers\n";
   for(int i = 0; i < amtToStore; i++){
      cout << pNums[i] << "\n";
   }



   return 0;
}
