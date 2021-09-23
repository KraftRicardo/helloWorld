#include "../h/main.h"


using namespace std;

static void generateSomeTables();
static void readAndWriteSomeTables();

int main() {
   cout << "STARTING MAIN ... " << endl;

//   generateSomeTables();

   Table t = readTable("spn/res/t4.csv");
//   t.print();

   vector<vector<vector<double>>>  listOfMatrices = calculateMatrices(t);
   for(vector<vector<double>> matrix : listOfMatrices){
      for(uint64_t row = 0; row < matrix[0].size(); row++){
         for(uint64_t column = 0; column < matrix.size(); column++){
            cout << matrix[column][row] << ", ";
         }
         cout << endl;
      }
      cout << "\n\n";
   }


//   splitFeaturesRDC(t, 0.1);

//   testGraph();

//   KMeans();

   cout << "END MAIN." << endl;
   return 0;
}

static void generateSomeTables(){
//   generateTable("spn/res/t1.csv");

   vector<string> names = {"A", "B"};
   vector<int> minRanges = {0, 0};
   vector<int> maxRanges = {9, 9};
   generateTable("spn/res/t5.csv", 2, 10, names,
                 minRanges, maxRanges);
}

void readAndWriteSomeTables() {
   Table t = readTable("spn/res/t1.csv");
   t.print();

   writeTable("spn/res/test", t);
   writeTable(t);
}
