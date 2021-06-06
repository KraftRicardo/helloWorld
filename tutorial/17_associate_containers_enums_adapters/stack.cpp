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

   // LIFO

   stack<string> custs;
   custs.push("George");
   custs.push("Louise");
   custs.push("Florence");

   int size = (int)custs.size();
   if(!custs.empty()){
      for(int i = 0; i < size; i++){
         cout << custs.top() << "\n";
         custs.pop();
      }
   }

   return 0;
}
