#include "../h/learnMSPN.h"

using namespace std;

// algorithm 3 of this paper: "Mixed Sum-Product Networks: A Deep Architecture for Hybrid Domains"

// d = table
// mue = minimum number of instances to split
// hsFactor = histogram smoothing factor
// alpha = threshold of significance

void learnMSPN(Table d, uint64_t mue, double hsFactor, double alpha) {
   // TODO implement when the other 2 algorithms work

   if(d.getNumberOfColumns() == 1){

   } else if(d.getNumberOfRows() < mue){

   } else{

   }
}

// TODO
// python lesen
// matrix build von python verstehen
// dann in c++ coden

// cca anschauen
// KMeans anschauen