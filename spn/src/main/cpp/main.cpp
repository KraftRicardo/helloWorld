#include "../h/main.h"

using namespace std;

static void generateSomeTables();
static void readAndWriteSomeTables();

int main() {
   cout << "STARTING MAIN ... " << endl;

   Table t = readTable("spn/res/t1.csv");
//   t.print();

   splitFeaturesRDC(t, 0.1);

//   testGraph();

   KMeans();

   cout << "END MAIN." << endl;
   return 0;
}

static void generateSomeTables(){
   generateTable("spn/res/t1.csv");

   vector<string> names = {"A", "B", "C", "D", "E", "F", "G", "H", "J", "K"};
   vector<int> minRanges = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   vector<int> maxRanges = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
   generateTable("spn/res/t3.csv", 10, 10000, names,
                 minRanges, maxRanges);
}

void readAndWriteSomeTables() {
   Table t = readTable("spn/res/t1.csv");
   t.print();

   writeTable("spn/res/test", t);
   writeTable(t);
}
