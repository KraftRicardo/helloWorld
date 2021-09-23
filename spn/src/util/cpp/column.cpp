#include <utility>

#include "../h/column.h"

using namespace std;

Column::Column(string newName, vector<uint64_t> newData) : name(move(newName)), data(move(newData)) {}

string Column::getName() {
   return name;
}

vector<uint64_t> Column::getData() const {
   return data;
}

void Column::print() {
   cout << "Column: " << name << endl;

   for(uint64_t i : data){
      cout << i << "\n";
   }
}

void Column::push_back(uint64_t i) {
   data.push_back(i);
}
