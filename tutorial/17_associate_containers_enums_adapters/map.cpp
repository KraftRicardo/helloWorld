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

   map<int, string> map1;
   map1.insert(pair<int, string>(1, "Bart"));
   map1.insert(pair<int, string>(2, "Lisa"));
   map1.insert(pair<int, string>(3, "Marge"));
   map1.insert(pair<int, string>(4, "Homer"));

   auto match = map1.find(1);
   cout << match->second << "\n";
   auto bart = map1.lower_bound(1);
   cout << "LB : " << bart->second << "\n";
   auto lisa = map1.upper_bound(1);
   cout << "UB : " << lisa->second << "\n";

   for(auto& it2 : map1){
      cout << "Key " << it2.first << "\n";
      cout << "Value " << it2.second << "\n";
   }

   return 0;
}
