#include "../h/phis.h"

using namespace std;

static const string PATH_PREFIX = "spn/res/tables/results/";

static const uint64_t K = 20;
static const double S = 1.0f / 6.0f;
static const int MEAN = 0;

static int counter = 0;

static dlib::matrix<double> calculateMatrix(const dlib::matrix<double> &column, const string &tableName);
static dlib::matrix<double> calcEmpiricalCompula(dlib::matrix<double> column);
static dlib::matrix<double> getRandomMatrix(long numberOfRows, long numberOfColumns, int mean, double standardDeviation);

vector<dlib::matrix<double>> rdc2(DlibTable table) {
   string folderName = table.getName();
   filesystem::create_directory(PATH_PREFIX + folderName);

   vector<dlib::matrix<double>> matrices = {};
   for(uint64_t j = 0; j < table.getNumberOfColumns(); j++){
      matrices.push_back(calculateMatrix(table.getColumn(j), folderName));
   }
   return matrices;
}

static dlib::matrix<double> calculateMatrix(const dlib::matrix<double> &column, const string &folderName) {
   cout << "column :\n" << column << endl;

   //get the empirical compula column
   dlib::matrix<double> empi = calcEmpiricalCompula(column);
   saveMatrixAsCsv(empi, PATH_PREFIX + folderName + "/empi_" + to_string(counter));

   //random gaussian
   dlib::matrix<double> gaussian = getRandomMatrix(2, K, MEAN, S);
   saveMatrixAsCsv(gaussian, PATH_PREFIX + folderName + "/gaussian_" + to_string(counter));

   // multiplication
   dlib::matrix<double> res = empi * gaussian;
   res = S / 2 * res;
   saveMatrixAsCsv(res, PATH_PREFIX + folderName + "/res_" + to_string(counter));

   // sin(res)
   for(long i = 0; i < res.nr(); i++){
      for(long j = 0; j < res.nc(); j++){
         res(i,j) = sin(res(i,j));
      }
   }
   saveMatrixAsCsv(res, PATH_PREFIX + folderName + "/sin(res)_" + to_string(counter));

   counter++;
   return res;
}

static dlib::matrix<double> calcEmpiricalCompula(dlib::matrix<double> column) {
   cout << "column\n" << column;

   long numberOfRows = column.nr();
   dlib::matrix<double> empi = dlib::ones_matrix<double>(numberOfRows, 2);

   for(long i = 0; i < numberOfRows; i++){
      double counter = 0;
      for(long j = 0; j < numberOfRows; j++){
         if(column(i, 0) >= column(j, 0)){
            counter++;
         }
      }
      empi(i, 0) = counter / static_cast<double>(numberOfRows);
   }

   return empi;
}

static dlib::matrix<double> getRandomMatrix(long numberOfRows, long numberOfColumns, int mean, double standardDeviation) {
   assert(numberOfRows > 0 && numberOfColumns > 0);

   default_random_engine generator(0);
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
