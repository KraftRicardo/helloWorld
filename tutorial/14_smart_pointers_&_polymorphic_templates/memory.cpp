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


void example(){
   int amtToStore;
   std::cout << "How many numbers do you want to store : ";
   std::cin >> amtToStore;
   int* pNums = (int *) malloc(static_cast<unsigned long>(amtToStore) * sizeof(int));

   if(pNums != NULL){
      int i = 0;
      while(i < amtToStore){
         cout << "Enter a Number : ";
         cin >> pNums[i];
         i++;
      }
   }

   cout << "You entered these numbers\n";
   for(int i = 0; i < amtToStore; i++){
      cout << pNums[i] << "\n";
   }

   // Delete the pointer
//   delete pNums; // TODO why does delete stop the application?
   free(pNums);
}

void example2(){
   uint64_t amtToStore;
   std::cout << "How many numbers do you want to store : ";
   std::cin >> amtToStore;
   uint64_t * pNums = (uint64_t  *) malloc(amtToStore * sizeof(uint64_t ));

   if(pNums != NULL){
      uint64_t  i = 0;
      while(i < amtToStore){
         cout << "Enter a Number : ";
         cin >> pNums[i];
         i++;
      }
   }

   cout << "You entered these numbers\n";
   for(uint64_t i = 0; i < amtToStore; i++){
      cout << pNums[i] << "\n";
   }

   free(pNums);
}

int main() {

   example();
   example2();

   return 0;
}
