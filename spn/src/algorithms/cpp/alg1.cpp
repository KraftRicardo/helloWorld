#include "../h/alg1.h"
#include "../h/dlibTable.h"

double doCCA(dlib::matrix<double>& m1, dlib::matrix<double>& m2);
using namespace std;

void printConnectedComponents(vector<dlib::matrix<double>> matrices, double alpha) {
   uint64_t size = matrices.size();
   DirectedGraph g = DirectedGraph(matrices.size());
   for(uint64_t i = 0; i < size; i++){
      for(uint64_t j = 0; j < size; j++){

         if(i != j){
            double correlation = doCCA(matrices[i], matrices[j]);
            cout << "correlation: " << i << " " << j << " " << "= " << correlation << endl;

            if(correlation < alpha){
               g.addEdge(i, j);
            }
         }
      }
   }

   g.printSCCs();
}

void testCCA(){
   dlib::matrix m1 = DlibTable("spn/res/t4.csv").getData();
   dlib::matrix m2 = DlibTable("spn/res/t4.csv").getData();
   double correlation = doCCA(m1, m2);
   cout << "correlation = " << correlation << endl;

}

double doCCA(dlib::matrix<double>& L, dlib::matrix<double>& R) {
   int rank = 9;
   dlib::matrix<double> Ltrans, Rtrans;
   dlib::matrix<double,0,1> correlations;

   double correlation = cca(L, R, Ltrans, Rtrans, rank);
//   cout << "LTrans: \n" << Ltrans << endl;
//   cout << "RTrans: \n" << Rtrans << endl;

   return correlation;
}
