#include "../h/main.h"

using namespace std;

int main() {
   cout << "Starting ... " << endl;

//   tableStuff();

   splitFeaturesRDC();










   cout << "Finish!" << endl;
   return 0;
}

void tableStuff(){
   generateTable("../spn/res/t1.csv");

   vector<string> names = {"A", "B", "C", "D", "E", "F", "G", "H", "J", "K"};
   vector<int> minRanges = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   vector<int> maxRanges = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
   generateTable("../spn/res/t2.csv", 10, 10000, names, minRanges, maxRanges);
}


