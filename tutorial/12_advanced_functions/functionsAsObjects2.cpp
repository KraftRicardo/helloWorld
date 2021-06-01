#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

using namespace std;


vector<int> changeList(vector<int> listOfNums, function<bool(int)> func);
bool isItOdd(int i);


int main() {

   vector<int> listOfNums {1, 2, 3, 4 ,5};
   vector<int> oddList = changeList(listOfNums, isItOdd);
   cout << "List of odds\n";
   for(auto i : oddList){
      cout << i << "\n";
   }

   return 0;
}

vector<int> changeList(vector<int> listOfNums, function<bool(int)> func){
   vector<int> result;
   for(int i : listOfNums){
      if(func(i)){
         result.push_back(i);
      }
   }
   return result;
}

bool isItOdd(int i){
   return i % 2;
}