#include "../h/mainGen.h"


using namespace std;

const string TABLES_PATH = "spn/res/tables/generated/";

void generateTable_M_100x3();
void generateTable_M_1000x4();
void generateTable_M_1000x6();

int main() {
   generateTable_M_100x3();
   generateTable_M_1000x4();
   generateTable_M_1000x6();
}

// A = uniform between 0 and 10
// B = 2 * A,
// C = 4 * A
void generateTable_M_100x3(){
   std::srand(std::time(nullptr));
   string path = "spn/res/tables/generated/M_100x3.csv";
   vector<string> columnNames = {"A", "B", "C"};

   dlib::matrix<double> data(100, 3);
   for(long i = 0; i < data.nr(); i++){
      double value = randDouble_uniform(0, 10);
      data(i,0) = value;
      data(i,1) = value * 2;
      data(i,2) = value * 4;
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}

// A = uniform between 0 and 100
// B = 2 * A
// C = uniform between 0 and 100
// D = 2 * C
void generateTable_M_1000x4(){
   std::srand(std::time(nullptr));
   string path = "spn/res/tables/generated/M_1000x4.csv";
   vector<string> columnNames = {"A", "B", "C", "D"};
   dlib::matrix<double> data(1000, 4);

   for(long i = 0; i < data.nr(); i++){
      for(long j = 0; j < data.nc(); j++){
         double value = randDouble_uniform(0, 100);
         data(i,0) = value;
         data(i,1) = value * 2;

         double value2 = randDouble_uniform(0, 100);
         data(i,2) = value2;
         data(i,3) = value2 * 2;
      }
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}

// A = uniform between 0 and 100
// B = 2 * A
// C = uniform between 0 and 100
// D = 2 * C
// E = uniform between 0 and 100
// F = 2 * E
void generateTable_M_1000x6(){
   std::srand(std::time(nullptr));
   string path = "spn/res/tables/generated/M_1000x6.csv";
   vector<string> columnNames = {"A", "B", "C", "D", "E", "F"};
   dlib::matrix<double> data(1000, 6);

   for(long i = 0; i < data.nr(); i++){
      for(long j = 0; j < data.nc(); j++){
         double value = randDouble_uniform(0, 100);
         data(i,0) = value;
         data(i,1) = value * 2;

         double value2 = randDouble_uniform(0, 100);
         data(i,2) = value2;
         data(i,3) = value2 * 2;

         double value3 = randDouble_uniform(0, 100);
         data(i,4) = value3;
         data(i,5) = value3 * 2;
      }
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}