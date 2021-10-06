#include "../h/util.h"

using namespace std;

void saveMatrixAsCsv(dlib::matrix<double> m, string filename) {
   cout << "Saving matrix in : " << filename << "... ";

   std::ofstream file(filename);
   if (!file.is_open()) {
      throw runtime_error("Could not open file: " + filename);
   } else {
      cout << "Writing matrix here: " << filename << "... \n";
   }

   for(long row = 0; row < m.nr(); row++){
      for(long column = 0; column < m.nc(); column++){
         file << m(row, column);
         if(column == m.nc() - 1){
            if(row != m.nr() - 1){
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

void pwd(){
   char tmp[256];
   getcwd(tmp, 256);
   cout << "Current working directory: " << tmp << endl;
}
