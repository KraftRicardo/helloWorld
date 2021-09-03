#include "../h/splitFeaturesRDC.h"

using namespace std;

static const uint64_t K = 20;
static const int MEAN = 0;
static const double S = 0.16666666666; // 1/6 does not work for the normal distribution?

static uint64_t numberOfRows;

static vector<double> calcCVi(Column column);
static void calcWiAndBi(double& bi, vector<double>& wi);
static double calcPhi(Column vi);
static void generateGraph(vector<double> phis, double alpha, uint64_t numberOfColumns);
static double calcCCA(double d, double j);

// d = table
// alpha = threshold of significance

// n = number of columns
// m = number of rows (or sample size per column, equal for all columns)
// cvi = empirical copula transformation (a vector per column)

void splitFeaturesRDC(Table d, float alpha) {
   cout << "Starting splitFeaturesRDC ... \n"
        << "Table: " << d.getName() << ", Alpha: " << alpha << endl;

   numberOfRows = d.getColumns()[0].getData().size();

   vector<double> phis = {};
   for (Column vi : d.getColumns()) { phis.push_back(calcPhi(vi)); }

   cout << "Phis: ";
   for (double i : phis) { cout << i << ", "; }
   cout << endl;

   generateGraph(phis, alpha, d.getColumns().size());

   cout << "Ending splitFeaturesRDC!" << endl;
}

void generateGraph(vector<double> phis, double alpha, uint64_t numberOfColumns) {
   DirectedGraph graph = DirectedGraph(numberOfColumns);

   for(uint64_t i = 0; i < phis.size(); i++){
      for(uint64_t j = 0; j < phis.size(); j++){
         if(i == j){ continue; }

         if(calcCCA(phis[i], phis[j]) > alpha){
            graph.addEdge(i, j);
         }
      }
   }

   cout << "Connected Components: ";
   graph.printSCCs();
}

double calcCCA(double d, double j) {
   // TODO Understand pseudo code. Ask Philipp!
   // What does the cov(double, double) mean?
   // Can I throw the values just in a eigen-value-problem-solver-library?
   return 0;
}

static double calcPhi(Column vi) {
   // (row 4) calculate cvi
   vector<double> cvi = calcCVi(vi);

   // (row 5)  (wi; bi) ∼ N(0k; sIk×k)
   double bi = 0;
   vector<double> wi = {};
   // TODO feed random seed before?
   calcWiAndBi(bi, wi);

   // (row 6) φ(CVi) = sin(wi · CVTi + bi)
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
   for (uint64_t i = 0; i < K; i++) { wi.push_back(distribution(generator)); }
}