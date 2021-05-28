#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> range(int start, int end, int step);
void printVec(vector<int>);

int main(){
   double investment = 0.0;
   double interestrate = 0.0;

   cout << "How much to invest : ";
   cin >> investment;
   cout << "Interest rate : ";
   cin >> interestrate;
   interestrate *= 0.01;

   for(int i = 0; i<10; i++){
      investment += (investment * interestrate);
   }

   cout << "Value after 10 years : " << investment << "\n";

   return 0;
}

vector<int> range(int start, int end, int step){
   vector<int> result;

   if(start == end){
      result.push_back(start);
   } else if(start < end) {
      for(int i = start; i <= end; i = i + step){
         result.push_back(i);
      }
   }

   return result;
}

void printVec(const vector<int> v){
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";
}