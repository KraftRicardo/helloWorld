#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void doubleArray(int* arr, int size){
   for(int i = 0; i < size; i++){
      arr[i] = arr[i] * 2;
   }
}

void printArr(int* arr, int size){
   cout << "Array: ";
   for(int i = 0; i <  size; i++){
      cout << arr[i] << " ";
   }
   cout << "\n";
}

int main(){
   int arr[] = {1, 2, 3, 4};
   doubleArray(arr, 4);

   printArr(arr, 4);

   for(int i = 0; i < 4; i++){
      arr[i] = 3;
   }

   printArr(arr, 4);

   for(auto &i : arr){
      i = 4;
   }

   printArr(arr, 4);

   return 0;
}