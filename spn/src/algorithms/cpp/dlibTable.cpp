#include "../h/dlibTable.h"

using namespace std;

DlibTable::DlibTable(string path) {
   this->path = path;
   readDlibTable();
}

DlibTable::DlibTable(std::vector<std::string> columnNames, dlib::matrix<double> data) {
   path = "no_set";
   this->columnNames = columnNames;
   this->data = data;
}

dlib::matrix<double> DlibTable::getColumn(uint64_t index) {
   assert(0 <= index && index < getNumberOfColumns());

   dlib::matrix<double> column;
   column.set_size(getNumberOfRows(), 1);

   for(int i = 0; i < data.nr(); i++){
      column(i, 0) = data(i, index);
   }
   return column;
}

uint64_t DlibTable::getNumberOfColumns() {
   return data.nc();
}

uint64_t DlibTable::getNumberOfRows() {
   return data.nr();
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
   cout << data;
}

// Getter
string DlibTable::getPath() {
   return path;
}

vector<string> DlibTable::getColumnNames() {
   return columnNames;
}

dlib::matrix<double> DlibTable::getData() {
   return data;
}

void DlibTable::readDlibTable() {
   std::ifstream file(path);
   if (!file.is_open()) {
      throw runtime_error("Could not open file: " + path);
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
   data = dlib::matrix<double>(numberOfLines, numberOfColumns);
   double value = 0;

   int row = 0;
   while (getline(file, line)) {
      stringstream ss(line);

      uint64_t column = 0;
      while (ss >> value) {
         data(row, column) = value;

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

void DlibTable::saveTableAsCsv(const string& filename) {
   cout << "Saving : " << path << " now at new file : " << filename << "... ";

   std::ofstream file(filename);
   if (!file.is_open()) {
      throw runtime_error("Could not open file: " + filename);
   } else {
      cout << "Writing table here: " << filename << "...";
   }

   // column names
   for (uint64_t i = 0; i < columnNames.size(); i++) {
      if(i == columnNames.size() - 1){
         file << columnNames[i] + "\n";
      } else {
         file << columnNames[i] + ","; // No comma at end of line
      }
   }

   // matrix
   for(long row = 0; row < data.nr(); row++){
      for(long column = 0; column < data.nc(); column++){
         file << data(row, column);
         if(column == data.nc() - 1){
            if(row != data.nr() - 1){
               file << "\n";
            }
         } else {
            file << ",";
         }
      }
   }

   file.close();
   cout << "Done." << endl;
}

std::string DlibTable::getName() {
   string baseFilename = path.substr(path.find_last_of("/\\") + 1);
   string::size_type const p(baseFilename.find_last_of('.'));
   return baseFilename.substr(0, p);
}

