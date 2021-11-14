#include "../h/mainGenerator.h"

using namespace std;

void generateTable_M_100x3();
void generateTable_M_1000x4();
void generateTable_M_1000x6();
void generateTable_t6();
void generateTable_t7();
void generateTable_t8();
void generateTable_t9();
void generateTable_t10();

// for performance test
void generateTable_PTest(string fileName, int numberOfRows);
void generateTable_PTest_2(int numColumns);

int main() {

   // performance test tables
   generateTable_PTest("10x10000", 10000);
   generateTable_PTest("10x20000", 20000);
   generateTable_PTest("10x30000", 30000);
   generateTable_PTest("10x40000", 40000);
   generateTable_PTest("10x50000", 50000);
   generateTable_PTest("10x60000", 60000);
   generateTable_PTest("10x70000", 70000);
   generateTable_PTest("10x80000", 80000);
   generateTable_PTest("10x90000", 90000);
   generateTable_PTest("10x100000", 100000);

   generateTable_PTest_2(5);
   generateTable_PTest_2(10);
   generateTable_PTest_2(15);
   generateTable_PTest_2(20);
   generateTable_PTest_2(25);
   generateTable_PTest_2(30);
   generateTable_PTest_2(35);
   generateTable_PTest_2(40);
   generateTable_PTest_2(45);
   generateTable_PTest_2(50);
   generateTable_PTest_2(55);
   generateTable_PTest_2(60);
   generateTable_PTest_2(65);
   generateTable_PTest_2(70);
   generateTable_PTest_2(75);
   generateTable_PTest_2(80);
   generateTable_PTest_2(85);
   generateTable_PTest_2(90);



   // int tables
//   generateTable_t6();
//   generateTable_t7();
//   generateTable_t8();
//   generateTable_t9();
//   generateTable_t10();

   // double tables
//   generateTable_M_100x3();
//   generateTable_M_1000x4();
//   generateTable_M_1000x6();
}

void generateTable_PTest(string fileName, int numberOfRows){
   std::srand(6);
   string path = "spn/res/tables/generated/P-Test/" + fileName + ".csv";
   vector<string> columnNames = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

   dlib::matrix<double> data(numberOfRows, 10);
   for(long i = 0; i < data.nr(); i++){
      for(long j = 0; j < data.nc(); j++){
         data(i,j) = randomInt_uniform(0, 10);
      }
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}

void generateTable_PTest_2(int numColumns){
   std::srand(6);
   string path = "spn/res/tables/generated/P-Test/" + to_string(numColumns) + "x10000.csv";

   dlib::matrix<double> data(10000, numColumns);
   for(long i = 0; i < data.nr(); i++){
      for(long j = 0; j < data.nc(); j++){
         data(i,j) = randomInt_uniform(0, 10);
      }
   }

   vector<string> columnNames;
   for(int i = 0; i < numColumns; i++){
      columnNames.push_back("A" + to_string(i));
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
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
      double value = randomDouble_uniform(0, 10);
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
         double value = randomDouble_uniform(0, 100);
         data(i,0) = value;
         data(i,1) = value * 2;

         double value2 = randomDouble_uniform(0, 100);
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
         double value = randomDouble_uniform(0, 100);
         data(i,0) = value;
         data(i,1) = value * 2;

         double value2 = randomDouble_uniform(0, 100);
         data(i,2) = value2;
         data(i,3) = value2 * 2;

         double value3 = randomDouble_uniform(0, 100);
         data(i,4) = value3;
         data(i,5) = value3 * 2;
      }
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}

// A = uniform between 0 and 10
// B = uniform between 0 and 10
// C = uniform between 0 and 10
void generateTable_t6(){
   std::srand(6);
   string path = "spn/res/tables/generated/t6.csv";
   vector<string> columnNames = {"A", "B", "C"};

   dlib::matrix<double> data(50, 3);
   for(long i = 0; i < data.nr(); i++){
      data(i,0) = randomInt_uniform(0, 10);
      data(i,1) = randomInt_uniform(0, 10);
      data(i,2) = randomInt_uniform(0, 10);
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}

// A = uniform between 0 and 10
// B = uniform between 0 and 10
// C = uniform between 0 and 10
void generateTable_t7(){
   std::srand(7);
   string path = "spn/res/tables/generated/t7.csv";
   vector<string> columnNames = {"A", "B", "C"};

   dlib::matrix<double> data(50, 3);
   for(long i = 0; i < data.nr(); i++){
      data(i,0) = randomInt_uniform(0, 10);
      data(i,1) = randomInt_uniform(0, 10);
      data(i,2) = randomInt_uniform(0, 10);
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}

// A = uniform between 0 and 10
// B = uniform between 0 and 10
// C = uniform between 0 and 10
// D = uniform between 0 and 10
// E = uniform between 0 and 10
void generateTable_t8(){
   std::srand(8);
   string path = "spn/res/tables/generated/t8.csv";
   vector<string> columnNames = {"A", "B", "C", "D", "E"};

   dlib::matrix<double> data(50, 5);
   for(long i = 0; i < data.nr(); i++){
      data(i,0) = randomInt_uniform(0, 10);
      data(i,1) = randomInt_uniform(0, 10);
      data(i,2) = randomInt_uniform(0, 10);
      data(i,3) = randomInt_uniform(0, 10);
      data(i,4) = randomInt_uniform(0, 10);
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}


void generateTable_t10(){
   std::srand(10);
   string path = "spn/res/tables/generated/t10.csv";
   vector<string> columnNames = {"A", "B", "C", "D", "E","F","G","H","I"};

   dlib::matrix<double> data(1000000, 5);
   for(long i = 0; i < data.nr(); i++){
      data(i,0) = randomInt_uniform(0, 10);
      data(i,1) = randomInt_uniform(0, 10);
      data(i,2) = randomInt_uniform(0, 10);
      data(i,3) = randomInt_uniform(0, 10);
      data(i,4) = randomInt_uniform(0, 10);
      data(i,5) = randomInt_uniform(0, 10);
      data(i,6) = randomInt_uniform(0, 10);
      data(i,7) = randomInt_uniform(0, 10);
      data(i,8) = randomInt_uniform(0, 10);
   }

   DlibTable(columnNames, data).saveTableAsCsv(path);
}