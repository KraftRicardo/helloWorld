#include "../h/table.h"

using namespace std;

Table::Table(std::string newName, std::vector<Column> newColumns) : name(std::move(newName)), columns(std::move(newColumns)) {
   assert(!columns.empty());

   uint64_t size = columns[0].getData().size();
   for(auto column : columns){
      assert(column.getData().size() == size);
   }
}

uint64_t Table::numberOfRows(){
   return columns[0].getData().size();
}
void Table::print(){
   cout << "TABLE: " << name << endl;

   for(auto & column : columns){
      cout << column.getName() << ", ";
   }
   cout << endl;

   for(uint64_t i = 0; i < numberOfRows(); i++){
      for(auto & column : columns){
         cout << column.getData()[i] << ", ";
      }
      cout << endl;
   }
}
