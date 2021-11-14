#include "../h/phis.h"

//#include <sys/time.h>
//struct timeval tp;
//gettimeofday(&tp, NULL);
//long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;


using namespace std;

static const uint64_t K = 20;
static const int MEAN = 0;
static const double S = 1.0f / 6.0f;

static vector<double> calcCVi(Column column, uint64_t numberOfRows);
static void calcWiAndBi(double& bi, vector<double>& wi);
static vector<vector<double>> calcPhi(Column vi, uint64_t numberOfRows);
static vector<vector<double>> generateMatrix(vector<double> cvi, vector<double> wi, double bi);
static void printPhis(vector<double>& phis);
static void printMatrix(vector<vector<double>> matrix);

// d = table
// alpha = threshold of significance

// n = number of columns
// m = number of rows (or sample size per column, equal for all columns)

vector<vector<vector<double>>> getPhis(Table d) {
   cout << "Starting getPhis ... \nTable: " << d.getName() << endl;

   // list of all matrices (1 per column)
   vector<vector<vector<double>>> phis = {};
   for (Column vi : d.getColumns()) {
      phis.push_back(calcPhi(vi, d.getNumberOfRows()));
   }

   for (vector<vector<double>> matrix : phis) {
      printMatrix(matrix);
   }

   return phis;
}

static vector<vector<double>> calcPhi(Column vi, uint64_t numberOfRows) {
   // (row 4) calculate cvi = "empirical copula transformation" (a vector per column)
   vector<double> cvi = calcCVi(vi, numberOfRows);

   // (row 5)  (wi; bi) ∼ N(0k; sIk×k)
   double bi = 0;
   vector<double> wi = {};
   calcWiAndBi(bi, wi); // TODO feed random seed before?

   // (row 6) φ(CVi) = sin(wi · CVTi + bi) TODO This line is probably a wrong interpretation of the pseudo code.
   return generateMatrix(cvi, wi, bi);
}

// TODO not working properly yet!
static vector<vector<double>> generateMatrix(vector<double> cvi, vector<double> wi, double bi) {
   // generate matrix with m x k
   vector<vector<double>> matrix;
   for (uint64_t column = 0; column < wi.size(); column++) {
      matrix.push_back(vector<double>{});
   }

   for (uint64_t row = 0; row < cvi.size(); row++) {
      for (int column = 0; column < wi.size(); column++) {
         // sin((cvi * wi) + bi)
         // matrix[row][column] = sin(cvi[row] * wi[column] + bi);
         matrix[row].push_back(sin(cvi[row] * wi[column] + bi));
      }
   }

   return matrix;
}

static vector<double> calcCVi(Column column, uint64_t numberOfRows) {
   vector<double> cvi = {};

   for (uint64_t vim : column.getData()) {
      double counter = 0;
      for (uint64_t vir : column.getData()) {
         if (vir <= vim) {
            counter++;
         }
      }
      cvi.push_back(counter / static_cast<double>(numberOfRows));
   }

   return cvi;
}

static void calcWiAndBi(double& bi, vector<double>& wi) {
   default_random_engine generator;
   normal_distribution<double> distribution(MEAN, S);

   bi = distribution(generator);
   for (uint64_t i = 0; i < K; i++) {
      wi.push_back(distribution(generator));
   }
}

void printPhis(vector<double>& phis) {
   cout << "Phis: ";
   for (double i : phis) {
      cout << i << ", ";
   }
   cout << endl;
}

void printMatrix(vector<vector<double>> matrix) {
   cout << "Printing matrix:\n";
   for (int row = 0; row < matrix[0].size(); row++) {
      for (int column = 0; column < matrix.size(); column++) {
         cout << matrix[row][column] << " ";
      }
      cout << "\n";
   }
}


