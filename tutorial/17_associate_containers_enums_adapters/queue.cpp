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

   // FIFO

   queue<string> cast;
   cast.push("Zoidberg");
   cast.push("Bender");
   cast.push("Leela");

   int size2 = (int)cast.size();
   if(!cast.empty()){
      for(int i = 0; i < size2; i++){
         cout << cast.front() << "\n";
         cast.pop();
      }
   }

   return 0;
}
