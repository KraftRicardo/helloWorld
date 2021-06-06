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
   set<int> set1{5, 4, 3, 1, 2, 1};
   cout << "Size : " << set1.size() << "\n";
   set1.insert(0);

   auto it = set1.begin();
   it++;
   cout << "2nd : " << *it << "\n";
   it = set1.end();
   advance(it, -2);
   set1.erase(it, set1.end());

   int arr[] = {8, 7, 6, 9};
   set1.insert(arr, arr + 4);

   auto val = set1.find(6);
   cout << "Found : " << *val << "\n";

   auto eight = set1.lower_bound(8);
   cout << "8 : " << *eight << "\n";

   auto nine = set1.upper_bound(8);
   cout << "9 : " << *nine << "\n";

   set<int> set2 {10, 11};
   set1.swap(set2);

   if (!set1.empty()) {
      for (int i : set1) {
         cout << i << " ";
      }
   }
   cout << "\n";

   if (!set2.empty()) {
      for (int i : set2) {
         cout << i << " ";
      }
   }
   cout << "\n";

   return 0;
}
