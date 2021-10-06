#include "tableGenerator.h"

using namespace std;

// saveFileName e.g. = "../spn/res/t1.csv"
void generateTable(string saveFileName){

   uint64_t size = 1000;

   vector<int> col1 = generateRandomVector(0, 5, size);
   vector<int> col2 = generateRandomVector(10, 20, size);
   vector<int> col3 = generateRandomVector(100, 200, size);
   vector<int> col4 = generateRandomVector(0, 1, size);
   vector<int> col5 = generateRandomVector(90, 99, size);

   pair<string, vector<int>> p1 = {"A", col1};
   pair<string, vector<int>> p2 = {"B", col2};
   pair<string, vector<int>> p3 = {"C", col3};
   pair<string, vector<int>> p4 = {"D", col4};
   pair<string, vector<int>> p5 = {"E", col5};

   vector<pair<string, vector<int>>> table = {p1, p2, p3, p4, p5};
   write_csv(saveFileName, table);
}

void generateTable(string saveFileName, uint64_t numberOfColumns, uint64_t columnSize, vector<string> names,
                   vector<int> minRanges, vector<int> maxRanges){

   vector<pair<string, vector<int>>> table = vector<pair<string, vector<int>>>();

   for(uint64_t i = 0; i < numberOfColumns; i++){
      vector<int> data = generateRandomVector(minRanges[i], maxRanges[i], columnSize);
      table.emplace_back(names[i], data);
   }

   write_csv(saveFileName, table);
}