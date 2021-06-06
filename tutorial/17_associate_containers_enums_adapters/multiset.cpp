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
   multiset<int> mset1{5, 4, 3, 1, 2, 1};

   mset1.insert(0);
   mset1.insert(4);

   if (!mset1.empty()) {
      for (int i : mset1) {
         cout << i << " ";
      }
   }
   cout << "\n";


   return 0;
}
