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

   enum day{Mon = 1, Tue, Wed, Thu, Fri = 6};

   enum day tuesday = Tue;
   cout << "Tuesday is the " << tuesday << "of the week\n";

   for(int i = Mon; i <= Fri; i++){
      cout << i << "\n";
   }

   return 0;
}
