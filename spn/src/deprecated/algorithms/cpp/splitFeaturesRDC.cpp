#include "../h/splitFeaturesRDC.h"

using namespace std;

static void generateGraph(vector<double> phis, double alpha, uint64_t numberOfColumns);
static double calcCCA(double d, double j);

// algorithm 1 of this paper: "Mixed Sum-Product Networks: A Deep Architecture for Hybrid Domains"
// d = table
// alpha = threshold of significance

void splitFeaturesRDC(Table d, double alpha) {
   cout << "Starting splitFeaturesRDC ... \n"
        << "Table: " << d.getName() << " Alpha: " << alpha << endl;

//   vector<double> phis = getPhis(d);
//   generateGraph(phis, alpha, d.getColumns().size());

   cout << "End splitFeaturesRDC!";
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