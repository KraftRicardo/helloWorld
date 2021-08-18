#include <utility>

#include "../h/column.h"

using namespace std;

Column::Column(std::string newName, std::vector<uint64_t> newData) : name(std::move(newName)), data(std::move(newData)) {}

std::string Column::getName() {
   return name;
}

std::vector<uint64_t> Column::getData() {
   return data;
}

void Column::print() {
   cout << "Column: " << name << endl;

   for(uint64_t i : data){
      cout << i << "\n";
   }
}
