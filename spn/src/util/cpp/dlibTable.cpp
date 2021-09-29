#include "../h/dlibTable.h"

using namespace std;

DlibTable::DlibTable(string path) {
   this->path = path;
   readDlibTable();
}

void DlibTable::readDlibTable() {
   ifstream file(path);
   if (!file.is_open()) {
      throw runtime_error("Could not open file");
   } else {
      cout << "Reading table: " << path << "... \n";
   }

   // column names
   string line;
   string columnName;
   columnNames = vector<string>{};

   if (file.good()) {
      getline(file, line);
      stringstream ss(line);

      while (getline(ss, columnName, ',')) {
         columnNames.push_back(columnName);
      }
   }

   // matrix
   uint64_t numberOfColumns = columnNames.size();
   uint64_t numberOfLines = countNumberOfLines(path) - 1; // do not count the first lines with the names
   matrix = dlib::matrix<double>(numberOfLines, numberOfColumns);
   double value = 0;

   int row = 0;
   while (getline(file, line)) {
      stringstream ss(line);

      uint64_t column = 0;
      while (ss >> value) {
         matrix(row, column) = value;

         if (ss.peek() == ',') {
            ss.ignore();
         }
         column++;
      }
      row++;
   }

   file.close();
}

uint64_t DlibTable::countNumberOfLines(const string& path) {
   uint64_t numLines = 0;
   ifstream file(path);
   string unused;
   while (getline(file, unused)) {
      ++numLines;
   }

   file.close();
   return numLines;
}

void DlibTable::print() {
   cout << "Table: " << path << endl;
   cout << "Size rows/columns : " << getNumberOfRows() << "/" << getNumberOfColumns() << endl;

   // column names
   for (uint64_t i = 0; i < columnNames.size(); i++) {
      cout << columnNames[i];
      if(i != columnNames.size() - 1){
         cout << " ";
      }
   }
   cout << endl;

   // matrix
   cout << matrix;
}

// Getter
uint64_t DlibTable::getNumberOfColumns() { return matrix.nc(); }
uint64_t DlibTable::getNumberOfRows() { return matrix.nr(); }
string DlibTable::getPath() { return path; }
vector<string> DlibTable::getColumnNames() { return columnNames; }
dlib::matrix<double> DlibTable::getMatrix() { return matrix; }