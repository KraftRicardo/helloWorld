#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include <deque>
#include <list>
#include <forward_list>

using namespace std;

int main() {

   deque<int> deq1;
   deq1.assign({11, 12});
   deq1.push_back(5);
   deq1.push_front(1);

   cout << "Size : " << deq1.size() << "\n";
   cout << deq1[0] << "\n";
   cout << deq1.at(1) << "\n";

   deque<int>::iterator it = deq1.begin() + 1;
   deq1.insert(it, 3);

   int tempArray[5] = {6, 7, 8, 9, 10};
   deq1.insert(deq1.end(), tempArray, tempArray + 5);

   deq1.erase(deq1.end());
   deq1.erase(deq1.begin(), deq1.begin() + 2);

   deq1.pop_front();
   deq1.pop_back();

   deque<int> deq2 = deque(2, 50);
//   deq1.swap(deq2);
//   deq1.clear();

   for(int i : deq1){
      cout << i << " ";
   }
   cout << "\n";


   for(int i : deq2){
      cout << i << " ";
   }
   cout << "\n";

   return 0;
}
