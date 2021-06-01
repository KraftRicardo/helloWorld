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

bool isEven(int i){
   return i%2;
}

int main() {
   forward_list<int> fl1;
   fl1.assign({1, 2, 3, 4});
   fl1.push_front(0);
   fl1.pop_front();

   cout << "Front : " << fl1.front() << "\n";
   forward_list<int>::iterator it4 = fl1.begin();
   it4 = fl1.insert_after(it4, 5);
   it4 = fl1.erase_after(fl1.begin());

   fl1.emplace_front(6);
   fl1.remove(6);
   fl1.remove_if(isEven);

   forward_list<int> fl2;
   fl2.assign({9, 8, 7, 6, 6});
   fl2.unique();
   fl2.reverse();

   fl1.merge(fl2);
   fl1.clear();

   for(int i : fl1){
      cout << i << " ";
   }
   cout << "\n";


   for(int i : fl2){
      cout << i << " ";
   }

   return 0;
}
