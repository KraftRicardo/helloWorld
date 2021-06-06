#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int main() {

   // queue, but sorts the values

   priority_queue<int> nums;
   nums.push(4);
   nums.push(8);
   nums.push(5);

   int size = (int) nums.size();
   if(!nums.empty()){
      for(int i = 0; i < size; i++){
         cout << nums.top() << "\n";
         nums.pop();
      }
   }

   return 0;
}
