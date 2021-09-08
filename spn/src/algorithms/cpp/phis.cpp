#include "../h/phis.h"

using namespace std;

static const uint64_t K = 20;
static const int MEAN = 0;
static const double S = 0.16666666666; // 1/6 does not work for the normal distribution?

static uint64_t numberOfRows;

static vector<double> calcCVi(Column column);
static void calcWiAndBi(double& bi, vector<double>& wi);
static double calcPhi(Column vi);

// d = table
// alpha = threshold of significance

// n = number of columns
// m = number of rows (or sample size per column, equal for all columns)

vector<double> getPhis(Table d) {
   cout << "Starting getPhis ... \n"
        << "Table: " << d.getName() << endl;

   numberOfRows = d.getColumns()[0].getData().size();

   vector<double> phis = {};
   for (Column vi : d.getColumns()) { phis.push_back(calcPhi(vi)); }

   cout << "Phis: ";
   for (double i : phis) { cout << i << ", "; }
   cout << endl;

   cout << "Ending getPhis!" << endl;
   return phis;
}

static double calcPhi(Column vi) {
   // (row 4) calculate cvi = "empirical copula transformation" (a vector per column)
   vector<double> cvi = calcCVi(vi);

   // (row 5)  (wi; bi) ∼ N(0k; sIk×k)
   double bi = 0;
   vector<double> wi = {};
   // TODO feed random seed before?
   calcWiAndBi(bi, wi);

   // (row 6) φ(CVi) = sin(wi · CVTi + bi)
   // TODO This line is probably a wrong interpretation of the pseudo code. Ask Philipp!
   return sin(inner_product(begin(wi), end(wi), std::begin(cvi), 0.0) + bi);
}

static vector<double> calcCVi(Column column) {
   vector<double> cvi = {};

   for (uint64_t vim : column.getData()) {
      double counter = 0;
      for (uint64_t vir : column.getData()) {
         if (vir <= vim) { counter++; }
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