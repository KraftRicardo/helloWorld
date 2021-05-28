#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void printHorizontalVector(vector<int> v);

int main(){
   vector<int> v = {23, 34, 2, 1, -1, 10, 320320, 2102, 2103, -213, -17};

   printHorizontalVector(v);

   return 0;
}

//------------------
//|  0  |  1  |  2  |
//------------------
//| 10  |  8  |  2  |
//------------------

void printHorizontalVector(vector<int> v){
   int size = (int) v.size();

   for(int i = 0; i < size; i++){
      cout << "------";
   }
   cout << "-\n";

   for(int i = 0; i < size; i++){
      printf("| %2d  ", i);
//      cout << "|  " << i << "  ";
   }
   cout << "|\n";

   for(int i = 0; i < size; i++){
      cout << "------";
   }
   cout << "-\n";

   for(int i : v){
      printf("| %2d  ", i);
   }
   cout << "|\n";

   for(int i = 0; i < size; i++){
      cout << "------";
   }
   cout << "-\n";
}