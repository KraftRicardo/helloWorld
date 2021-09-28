#include "../h/rdcTransform.h"

using namespace std;

static const uint64_t K = 16;
static const double S = 1.0f / 6.0f;
static const int MEAN = 0;

static vector<vector<double>> calculateMatrix(const Column &column);
static vector<double> getRandomNormalValues(const uint64_t size, int mean, double standardDeviation);
static vector<double> calcEmpiricalCopula(const Column &column);
static vector<vector<double>> calcMult(const vector<double> &empi, const vector<double> &wis, const vector<double> &bis);

vector<vector<vector<double>>> calculateMatrices(Table table) {
   vector<vector<vector<double>>> matrices = {};
   for(const Column& column : table.getColumns()){
      matrices.push_back(calculateMatrix(column));
   }
   return matrices;
}

static vector<vector<double>> calculateMatrix(const Column &column) {
   //transform through the empirical copula
   vector<double> empi = calcEmpiricalCopula(column);

   //random gaussian
   vector<double> wis = getRandomNormalValues(K, MEAN, S);
   vector<double> bis = getRandomNormalValues(K, MEAN, S);
   
   // sin((cvi * wi) + bi)
   return calcMult(empi, wis, bis);
}

static vector<vector<double>> calcMult(const vector<double> &empi, const vector<double> &wis, const vector<double> &bis) {
   vector<vector<double>> result = {}; // matrix size of this = empi.size() x K
   uint64_t rows = empi.size();

   for(int i = 0; i < K; i++){
      result.emplace_back(rows);
   }

   for(uint64_t row = 0; row < rows; row++){
      for(uint64_t column = 0; column < K; column++){
         result[column][row] = sin(S / 2 * (empi[row] * wis[column] + 1 * bis[column]) );
      }
   }
   return result;
}

// calculate the percentage of how many elements in the column are smaller than the looked at element
static vector<double> calcEmpiricalCopula(const Column &column) {
   vector<double> cvi = {};
   double numberOfRows = static_cast<double>(column.getData().size());

   for (uint64_t elem : column.getData()) {
      double counter = 0;
      for (uint64_t elem2 : column.getData()) {
         if (elem2 <= elem) {
            counter++;
         }
      }
      cvi.push_back(counter / numberOfRows);
   }

   return cvi;
}

static vector<double> getRandomNormalValues(uint64_t size, int mean, double standardDeviation) {
   default_random_engine generator;
   normal_distribution<double> distribution(mean, standardDeviation);

   vector<double> values = {};
   for(uint64_t i = 0; i < size; i++){
      values.push_back(distribution(generator));
   }
   return values;
}

