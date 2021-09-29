#pragma once

#include <string>
#include <vector>
#include <dlib/matrix.h>

class DlibTable {
   private:
   std::string path;
   std::vector<std::string> columnNames;
   dlib::matrix<double> matrix;

   void readDlibTable();
   static uint64_t countNumberOfLines(const std::string& basicString);

   public:
   explicit DlibTable(std::string path);

   uint64_t getNumberOfColumns();
   uint64_t getNumberOfRows();
   void print();

   // Getter
   std::string getPath();
   std::vector<std::string> getColumnNames();
   dlib::matrix<double> getMatrix();
};