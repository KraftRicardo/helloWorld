#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void range(int start, int end, int step);
void printVec(vector<int>);

int main(){
   range(0, 10, 2);
   range(-3, 10, 2);
   range(10, 10, 2);
   range(22, 10, 2);
   range(-22, -10, 2);
   range(-22, -10, 5);

   return 0;
}

void range(int start, int end, int step){
   vector<int> result;

   if(start == end){
      result.push_back(start);
   } else if(start < end) {
      for(int i = start; i <= end; i = i + step){
         result.push_back(i);
      }
   }

   printVec(result);
}

void printVec(const vector<int> v){
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";
}