#include "../h/util.h"

using namespace std;

void print(const std::vector<int>& column){
   for(int i : column){
      cout << i << endl;
   }
}

void printWorkingDirectory() {
   std::cout << "Current path is " << filesystem::current_path() << '\n';
}
