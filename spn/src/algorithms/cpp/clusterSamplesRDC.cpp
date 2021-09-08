#include "../h/clusterSamplesRDC.h"

using namespace std;

static const int KMEANS_PARAMETER = 2;

static void kMeans(vector<double> E, int v);

// algorithm 2 of this paper: "Mixed Sum-Product Networks: A Deep Architecture for Hybrid Domains"
// d = table

void clusterSamplesRDC(Table d) {
   cout << "Starting clusterSamplesRDC ... \n"
        << "Table: " << d.getName() << endl;


   // TODO We do not calculate the phis the same way as in the first algorithm, since there is no for loop ( for each Vi element V do ... )
   vector<double> phis = getPhis(d);

   // TODO Does this mean we have 5 columns and want 2 sets?
   kMeans(phis, KMEANS_PARAMETER);

   cout << "End clusterSamplesRDC";
}

void kMeans(vector<double> E, int v) {
   cout << "Doing KMeans with parameter : " << v;

   // TODO self implementation OR find a usuable lib (nothing found yet)
}
