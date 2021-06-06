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

   multimap<int, string> mmap1;
   mmap1.insert(pair<int, string>(1, "Bart"));
   mmap1.insert(pair<int, string>(1, "Lisa"));
   mmap1.insert(pair<int, string>(3, "Marge"));

   auto match = mmap1.find(1);
   cout << match->second << "\n";

   for(auto& it2 : mmap1){
      cout << "Key " << it2.first << "\n";
      cout << "Value " << it2.second << "\n";
   }

   return 0;
}
