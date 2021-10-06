#include "dlibRdcTransform.h"

using namespace std;

static const uint64_t K = 20;
static const double S = 1.0f / 6.0f;
static const int MEAN = 0;

static dlib::matrix<double> calculateMatrix(dlib::matrix<double> column);
static dlib::matrix<double> calcEmpiricalCompula(dlib::matrix<double> column);
static dlib::matrix<double> getRandomMatrix(long numberOfRows, long numberOfColumns, int mean, double standardDeviation);
static dlib::matrix<double> calcMult(const dlib::matrix<double> &empi, const dlib::matrix<double> &wis, const dlib::matrix<double> &bis);

vector<dlib::matrix<double>> calculateMatrices(DlibTable table) {
   vector<dlib::matrix<double>> matrices = {};
   for(uint64_t column = 0; column < table.getNumberOfColumns(); column++){
      matrices.push_back(calculateMatrix(table.getColumn(column)));
   }
   return matrices;
}

static dlib::matrix<double> calculateMatrix(dlib::matrix<double> column) {
   cout << "column :\n" << column << endl;

   //get the empirical compula column
   dlib::matrix<double> empi = calcEmpiricalCompula(column);

   //random gaussian
   dlib::matrix<double> wis = getRandomMatrix(1, K, MEAN, S);
   dlib::matrix<double> bis = getRandomMatrix(1, K, MEAN, S);

   // sin((cvi * wi) + bi)
   return calcMult(empi, wis, bis);
}

static dlib::matrix<double> calcMult(const dlib::matrix<double> &empi, const dlib::matrix<double> &wis, const dlib::matrix<double> &bis) {
   dlib::matrix<double> result;
   result.set_size(empi.nr(), K);

   for(uint64_t row = 0; row < empi.nr(); row++){
      for(uint64_t column = 0; column < K; column++){
         result(row, column) = sin(S / 2 * (empi(row, 0) * wis(0, column) + bis(0, column)));
      }
   }

   return result;
}

static dlib::matrix<double> calcEmpiricalCompula(dlib::matrix<double> column) {
   long numberOfRows = column.nr();
   dlib::matrix<double> empi;
   empi.set_size(numberOfRows, 1);

   for(long i = 0; i < numberOfRows; i++){
      double counter = 0;
      for(long j = 0; j < numberOfRows; j++){
         if(column(i, 0) <= column(j, 0)){
            counter++;
         }
      }
      empi(i, 0) = counter / static_cast<double>(numberOfRows);
   }

   return empi;
}

static dlib::matrix<double> getRandomMatrix(long numberOfRows, long numberOfColumns, int mean, double standardDeviation) {
   assert(numberOfRows > 0 && numberOfColumns > 0);

   default_random_engine generator;
   normal_distribution<double> distribution(mean, standardDeviation);

   dlib::matrix<double> m;
   m.set_size(numberOfRows, numberOfColumns);
   for(long i = 0; i < numberOfRows; i++){
      for(long j = 0; j < numberOfColumns; j++){
         m(i, j) = distribution(generator);
      }
   }

   return m;

//   TODO wie kann ich diese Zeile richtig benutzen?
//   algorithms::matrix m = algorithms::randm(numberOfRows, numberOfColumns, distribution);

//   TODO: Warum geht diese Zeile nicht?
//   algorithms::matrix m = algorithms::randm(numberOfRows, numberOfColumns, normal_distribution<double> (mean, standardDeviation));
}