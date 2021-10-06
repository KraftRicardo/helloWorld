#pragma once

#include <string>
#include <vector>
#include <dlib/matrix.h>

class DlibTable {
   private:
   std::string path;
   std::vector<std::string> columnNames;
   dlib::matrix<double> data;

   void readDlibTable();
   static uint64_t countNumberOfLines(const std::string& basicString);

   public:
   DlibTable(std::string path);
   DlibTable(std::vector<std::string> columnNames, dlib::matrix<double> data);

   dlib::matrix<double> getColumn(uint64_t index);
   uint64_t getNumberOfColumns();
   uint64_t getNumberOfRows();
   void print();
   void saveTableAsCsv(const std::string& filename);
   std::string getName();

   // Getter
   std::string getPath();
   std::vector<std::string> getColumnNames();
   dlib::matrix<double> getData();
};