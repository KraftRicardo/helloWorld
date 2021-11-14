#include "../h/phis.h"

using namespace std;

static const string PATH_PREFIX = "spn/res/tables/results/";

static const uint64_t K = 20;
static const double S = 1.0f / 6.0f;
static const int MEAN = 0;

static int counter = 0;

static dlib::matrix<double> calculateMatrix(const dlib::matrix<double>& column);
static dlib::matrix<double> calcEmpiricalCompulaTransformation(dlib::matrix<double> column);
static dlib::matrix<double> getRandomMatrix(long numberOfRows, long numberOfColumns, int mean, double standardDeviation);
static dlib::matrix<double> calculateMatrixWithTimeEachStep(const dlib::matrix<double>& column);


vector<dlib::matrix<double>> rdc2(DlibTable table) {
//   string folderName = table.getName();
//   filesystem::create_directory(PATH_PREFIX + folderName);

   vector<dlib::matrix<double>> matrices = {};
   for (uint64_t j = 0; j < table.getNumberOfColumns(); j++) {
      matrices.push_back(calculateMatrix(table.getColumn(j)));
//      matrices.push_back(calculateMatrixWithTimeEachStep(table.getColumn(j)));
   }
   return matrices;
}

long timeStamp2(){
   struct timeval tp;
   gettimeofday(&tp, NULL);
   long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
   return ms;
}

static dlib::matrix<double> calculateMatrix(const dlib::matrix<double>& column) {
   //get the empirical compula column
   dlib::matrix<double> empi = calcEmpiricalCompulaTransformation(column);

   //random gaussian
   dlib::matrix<double> gaussian = getRandomMatrix(2, K, MEAN, S);

   // multiplication
   dlib::matrix<double> res = empi * gaussian;

   // sin(res)
   for (long i = 0; i < res.nr(); i++) {
      for (long j = 0; j < res.nc(); j++) {
         res(i, j) = sin(S/2 * res(i, j));
      }
   }

   counter++;
   return res;
}

static dlib::matrix<double> calculateMatrixWithTimeEachStep(const dlib::matrix<double>& column) {
   //get the empirical compula column
   long startTime = timeStamp2();
   dlib::matrix<double> empi = calcEmpiricalCompulaTransformation(column);
   long endTime = timeStamp2();
   cout << "Time_Empi = " << endTime - startTime << endl;

   long startTime3 = timeStamp2();
   //random gaussian
   dlib::matrix<double> gaussian = getRandomMatrix(2, K, MEAN, S);
   long endTime3 = timeStamp2();
   cout << "Time_Gaussian = " << endTime3 - startTime3 << endl;


   long startTime4 = timeStamp2();
   // multiplication
   dlib::matrix<double> res = empi * gaussian;
   //   res = S / 2 * res;
   long endTime4 = timeStamp2();
   cout << "Time_Multiplication = " << endTime4 - startTime4 << endl;

   long startTime5 = timeStamp2();
   // sin(res)
   for (long i = 0; i < res.nr(); i++) {
      for (long j = 0; j < res.nc(); j++) {
         res(i, j) = sin(S/2 * res(i, j));
      }
   }
   long endTime5 = timeStamp2();
   cout << "Time_Sinus = " << endTime5 - startTime5 << endl;

   counter++;
   return res;
}

static dlib::matrix<double> calculateMatrixWithSave(const dlib::matrix<double>& column, const string& folderName) {
   cout << "column :\n" << column << endl;

   //get the empirical compula column
   dlib::matrix<double> empi = calcEmpiricalCompulaTransformation(column);
   saveMatrixAsCsv(empi, PATH_PREFIX + folderName + "/empi_" + to_string(counter));

   //random gaussian
   dlib::matrix<double> gaussian = getRandomMatrix(2, K, MEAN, S);
   saveMatrixAsCsv(gaussian, PATH_PREFIX + folderName + "/gaussian_" + to_string(counter));

   // multiplication
   dlib::matrix<double> res = empi * gaussian;
   res = S / 2 * res;
   saveMatrixAsCsv(res, PATH_PREFIX + folderName + "/res_" + to_string(counter));

   // sin(res)
   for (long i = 0; i < res.nr(); i++) {
      for (long j = 0; j < res.nc(); j++) {
         res(i, j) = sin(res(i, j));
      }
   }
   saveMatrixAsCsv(res, PATH_PREFIX + folderName + "/sin(res)_" + to_string(counter));

   counter++;
   return res;
}

// O(N(log(N))
// column: 1 2 1 3 1 3 1 2
// my_vector: 1 1 1 1 2 2 3 3
// numberToCount: 1->4, 2->6, 3->8
static dlib::matrix<double> calcEmpiricalCompulaTransformation(dlib::matrix<double> column) {
   // sort numbers, O(Nlog(N))
   vector<double> my_vector(column.begin(), column.end());
   sort(my_vector.begin(), my_vector.end());

   // create mapping number to #numbers lower than the number, O(N)
   unordered_map<double, int> numberToCount;
   for(int i = 0; i < my_vector.size(); i++){
      numberToCount[my_vector[i]] = i + 1;
   }

   // create empi column, O(N)
   int numberOfColumns = column.nr();
   dlib::matrix<double> empi = dlib::ones_matrix<double>(numberOfColumns, 2);
   for (long i = 0; i < numberOfColumns; i++) {
      empi(i, 0) = numberToCount[column(i, 0)] / static_cast<double>(numberOfColumns);
   }

   return empi;
}

static dlib::matrix<double> calcEmpiricalCompulaTransformation2(dlib::matrix<double> column) {
   //   cout << "column\n" << column;

   long numberOfRows = column.nr();
   dlib::matrix<double> empi = dlib::ones_matrix<double>(numberOfRows, 2);

   for (long i = 0; i < numberOfRows; i++) {
      double counter = 0;
      for (long j = 0; j < numberOfRows; j++) {
         if (column(j, 0) <= column(i, 0)) {
            counter++;
         }
      }
      empi(i, 0) = counter / static_cast<double>(numberOfRows);
   }

   return empi;
}

static dlib::matrix<double> getRandomMatrix(long numberOfRows, long numberOfColumns, int mean,
                                            double standardDeviation) {
   assert(numberOfRows > 0 && numberOfColumns > 0);

   default_random_engine generator(0);
   normal_distribution<double> distribution(mean, standardDeviation);

   dlib::matrix<double> m;
   m.set_size(numberOfRows, numberOfColumns);
   for (long i = 0; i < numberOfRows; i++) {
      for (long j = 0; j < numberOfColumns; j++) {
         m(i, j) = distribution(generator);
      }
   }

   return m;

   //   TODO wie kann ich diese Zeile richtig benutzen?
   //   algorithms::matrix m = algorithms::randm(numberOfRows, numberOfColumns, distribution);

   //   TODO: Warum geht diese Zeile nicht?
   //   algorithms::matrix m = algorithms::randm(numberOfRows, numberOfColumns, normal_distribution<double> (mean, standardDeviation));
}