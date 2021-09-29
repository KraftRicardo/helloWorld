#include "../h/csvImporter.h"
#include "../../util/h/dlibTable.h"

using namespace std;

int testCsvImporter() {
   // write test
   vector<int> vec1(100, 1);
   vector<int> vec2(100, 2);
   vector<int> vec3(100, 3);

   vector<pair<string, vector<int>>> dataset = {{"One", vec1}};
   write_csv(ONE_COLUMN, dataset);

   vector<pair<string, vector<int>>> dataset2 = {{"One", vec1}, {"Two", vec2}, {"Three", vec3}};
   write_csv(THREE_COLUMNS, dataset2);

   // read test
   vector<pair<string, vector<int>>> ones = read_csv(ONE_COLUMN);
   vector<pair<string, vector<int>>> three_cols = read_csv(THREE_COLUMNS);

   write_csv(OUTPUT_ONES, ones);
   write_csv(OUTPUT_THREE, three_cols);

   return 0;
}

void write_csv(const string& filename, vector<pair<string, vector<int>>> dataset) {
   std::ofstream myFile(filename);

   // Send column names to the stream
   for (uint64_t j = 0; j < dataset.size(); j++) {
      myFile << dataset.at(j).first;

      if (j != dataset.size() - 1) {
         myFile << ","; // No comma at end of line
      }
   }
   myFile << "\n";

   // Send data to the stream
   uint64_t columnSize = dataset.at(0).second.size();
   for (uint64_t row = 0; row < columnSize; row++) {
      for (uint64_t column = 0; column < dataset.size(); column++) {
         myFile << dataset.at(column).second.at(row);

         if (column != dataset.size() - 1) {
            myFile << ","; // No comma at end of line
         }
      }
      myFile << "\n";
   }

   myFile.close();
}

void writeTable(Table table){
   writeTable(table.getPath(), table);
}

void writeTable(const string& path, Table table) {
   std::ofstream csvFile(path);

   // first line (column names)
   for(Column column : table.getColumns()){
      csvFile << column.getName() << ",";
   }
   csvFile << "\n";

   // rest lines (values)
   for(uint64_t row = 0; row < table.getColumns()[0].getData().size(); row++){
      for(Column column : table.getColumns()){
         csvFile << column.getData()[row] << ",";
      }
      csvFile << "\n";
   }

   csvFile.close();
}

// Reads a CSV file into a vector of <string, vector<int>> pairs where each pair represents <column name, column values>
vector<pair<string, vector<int>>> read_csv(const string& filename) {
   vector<pair<string, vector<int>>> result;
   std::ifstream myFile(filename);

   string line;
   string colName;
   int val = 0;

   if (!myFile.is_open()) {
      throw std::runtime_error("Could not open file");
   }

   // column names
   if (myFile.good()) {
      getline(myFile, line);
      stringstream ss(line);

      while (getline(ss, colName, ',')) {
         result.push_back({colName, vector<int>{}});
      }
   }

   // column values
   while (getline(myFile, line)) {
      stringstream ss(line);

      uint64_t column = 0;
      while (ss >> val) {
         result.at(column).second.push_back(val);

         if (ss.peek() == ',') {
            ss.ignore();
         }
         column++;
      }
   }

   myFile.close();
   return result;
}

Table readTable(const string& filename) {
   std::ifstream file(filename);
   if (!file.is_open()) {
      throw std::runtime_error("Could not open file");
   }

   string line;
   string columnName;
   vector<Column> columns = {};
   uint64_t value = 0;

   // column names
   if (file.good()) {
      getline(file, line);
      stringstream ss(line);

      while (getline(ss, columnName, ',')) {
         columns.push_back(Column(columnName, vector<uint64_t>{}));
      }
   }

   // column values
   while (getline(file, line)) {
      stringstream ss(line);

      uint64_t column = 0;
      while (ss >> value) {
         columns.at(column).push_back(value);

         if (ss.peek() == ',') {
            ss.ignore();
         }
         column++;
      }
   }

   file.close();
   return Table(filename, columns);
}



