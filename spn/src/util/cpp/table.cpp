#include "../h/table.h"

using namespace std;

Table::Table(std::string newPath, std::vector<Column> newColumns) : path(std::move(newPath)), columns(std::move(newColumns)) {
   assert(!columns.empty());
   assert(!path.empty());

   name = filesystem::path(path).filename();

   uint64_t size = columns[0].getData().size();
   for(auto column : columns){
      assert(column.getData().size() == size);
   }
}

uint64_t Table::numberOfRows(){
   return columns[0].getData().size();
}

void Table::print(){
   cout << "PRINTING TABLE: " << name << " PATH: " << path << endl;

   //names
   for(auto & column : columns){
      cout << column.getName() << ", ";
   }
   cout << endl;

   //values
   for(uint64_t i = 0; i < numberOfRows(); i++){
      for(auto & column : columns){
         cout << column.getData()[i] << ", ";
      }
      cout << endl;
   }
}

std::string Table::getName() {
   return name;
}

std::string Table::getPath() {
   return path;
}

std::vector<Column> Table::getColumns() {
   return columns;
}
