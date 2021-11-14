#include "../h/alg1.h"
#include "../../util/h/dlibTable.h"

double cca(dlib::matrix<double>& L, dlib::matrix<double>& R);
double ccaWithExtraOnesColumn(dlib::matrix<double>& L, dlib::matrix<double>& R);
double ccaMatrixAsVectors(dlib::matrix<double>& L, dlib::matrix<double>& R);
double ccaWithExtraOnesColumnsAndMatrixAsVectors(dlib::matrix<double>& L, dlib::matrix<double>& R);
using namespace std;

void printConnectedComponents(vector<dlib::matrix<double>> matrices, double alpha) {
   uint64_t size = matrices.size();
   DirectedGraph g = DirectedGraph(matrices.size());
   for(uint64_t i = 0; i < size; i++){
      for(uint64_t j = 0; j < size; j++){
         if(i != j){
            double correlation = cca(matrices[i], matrices[j]);
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
//   dlib::matrix m1 = DlibTable("spn/res/tables/generated/t6.csv").getData();
//   dlib::matrix m2 = DlibTable("spn/res/tables/generated/t7.csv").getData();

//   dlib::matrix m1 = DlibTable("spn/res/tables/generated/t8.csv").getData();
//   dlib::matrix m2 = DlibTable("spn/res/tables/generated/t9.csv").getData();

//   dlib::matrix m1 = DlibTable("spn/res/tables/results/t4/sin(res)_0").getData();
//   dlib::matrix m2 = DlibTable("spn/res/tables/results/t4/sin(res)_1").getData();

   dlib::matrix m1 = DlibTable("spn/res/tables/results/t3/sin(res)_0").getData();
   dlib::matrix m2 = DlibTable("spn/res/tables/results/t3/sin(res)_1").getData();

   cout << "####cca####" << endl;
   cca(m1, m2);
   cout << "####ccaWithExtraOnesColumn####" << endl;
   ccaWithExtraOnesColumn(m1, m2);
   cout << "####ccaMatrixAsVectors####" << endl;
   ccaMatrixAsVectors(m1, m2);
   cout << "####ccaWithExtraOnesColumnsAndMatrixAsVectors####" << endl;
   ccaWithExtraOnesColumnsAndMatrixAsVectors(m1, m2);
}

double cca(dlib::matrix<double>& L, dlib::matrix<double>& R) {
   int numCorrelations = 9;
   dlib::matrix<double> Ltrans, Rtrans;
   dlib::matrix<double,0,1> correlations;

//   cout << "L : \n" << L << endl;
//   cout << "R : \n" << R << endl;


   /*!
        source: http://dlib.net/dlib/statistics/cca_abstract.h.html
        requires
            - num_correlations > 0
            - L.size() > 0
            - R.size() > 0
            - L.nr() == R.nr()
            - regularization >= 0
        ensures
            - This function performs a canonical correlation analysis between the row
              vectors in L and R.  That is, it finds two transformation matrices, Ltrans
              and Rtrans, such that row vectors in the transformed matrices L*Ltrans and
              R*Rtrans are as correlated as possible.  That is, we try to find two transforms
              such that the correlation values returned by compute_correlations(L*Ltrans, R*Rtrans)
              would be maximized.
            - Let N == min(num_correlations, min(R.nr(),min(L.nc(),R.nc())))
              (This is the actual number of elements in the transformed vectors.
              Therefore, note that you can't get more outputs than there are rows or
              columns in the input matrices.)
            - #Ltrans.nr() == L.nc()
            - #Ltrans.nc() == N
            - #Rtrans.nr() == R.nc()
            - #Rtrans.nc() == N
            - This function assumes the data vectors in L and R have already been centered
              (i.e. we assume the vectors have zero means).  However, in many cases it is
              fine to use uncentered data with cca().  But if it is important for your
              problem then you should center your data before passing it to cca().
            - This function works with reduced rank approximations of the L and R matrices.
              This makes it fast when working with large matrices.  In particular, we use
              the svd_fast() routine to find reduced rank representations of the input
              matrices by calling it as follows: svd_fast(L, U,D,V, num_correlations+extra_rank, q)
              and similarly for R.  This means that you can use the extra_rank and q
              arguments to cca() to influence the accuracy of the reduced rank
              approximation.  However, the default values should work fine for most
              problems.
            - returns an estimate of compute_correlations(L*#Ltrans, R*#Rtrans).  The
              returned vector should exactly match the output of compute_correlations()
              when the reduced rank approximation to L and R is accurate and regularization
              is set to 0.  However, if this is not the case then the return value of this
              function will deviate from compute_correlations(L*#Ltrans, R*#Rtrans).  This
              deviation can be used to check if the reduced rank approximation is working
              or you need to increase extra_rank.
            - The dimensions of the output vectors produced by L*#Ltrans or R*#Rtrans are
              ordered such that the dimensions with the highest correlations come first.
              That is, after applying the transforms produced by cca() to a set of vectors
              you will find that dimension 0 has the highest correlation, then dimension 1
              has the next highest, and so on.  This also means that the list of numbers
              returned from cca() will always be listed in decreasing order.
            - This function performs the ridge regression version of Canonical Correlation
              Analysis when regularization is set to a value > 0.  In particular, larger
              values indicate the solution should be more heavily regularized.  This can be
              useful when the dimensionality of the data is larger than the number of
              samples.
            - A good discussion of CCA can be found in the paper "Canonical Correlation
              Analysis" by David Weenink.  In particular, this function is implemented
              using equations 29 and 30 from his paper.  We also use the idea of doing CCA
              on a reduced rank approximation of L and R as suggested by Paramveer S.
              Dhillon in his paper "Two Step CCA: A new spectral method for estimating
              vector models of words".
    !*/
   auto correlation = dlib::cca(L, R, Ltrans, Rtrans, numCorrelations);

   cout << "LTrans: \n" << Ltrans << endl;
   cout << "RTrans: \n" << Rtrans << endl;
   cout << "correlation = \n" << correlation << endl;

   // TODO cca Die Dimension von correlation hängt von der Dimension von RTrans, LTrans ab?
   return correlation;
}

dlib::matrix<double> addOnesColumn(dlib::matrix<double> m){
   dlib::matrix<double> m2(m.nr(), m.nc() + 1);
   for(long i = 0; i < m.nr(); i++){
      for(long j = 0; j < m.nc(); j++){
         m2(i,j) = m(i,j);
      }
      m2(i, m.nc()) = 1;
   }
   return m2;
}

double ccaWithExtraOnesColumn(dlib::matrix<double>& L, dlib::matrix<double>& R){
   dlib::matrix<double> L2 = addOnesColumn(L);
   dlib::matrix<double> R2 = addOnesColumn(R);

   return cca(L2, R2);
}

dlib::matrix<double> matrixToVector(dlib::matrix<double> m){
   dlib::matrix<double> vector(m.nr() * m.nc(), 1);
   for(long i = 0; i < m.nr(); i++){
      for(long j = 0; j < m.nc(); j++){
         vector(i + j * i, 1) = m(i,j);
      }
   }
   return vector;
}

double ccaMatrixAsVectors(dlib::matrix<double>& L, dlib::matrix<double>& R){
   dlib::matrix<double> vectorL = matrixToVector(L);
   dlib::matrix<double> vectorR = matrixToVector(R);

   return cca(vectorL, vectorR);
}

double ccaWithExtraOnesColumnsAndMatrixAsVectors(dlib::matrix<double>& L, dlib::matrix<double>& R){
   dlib::matrix<double> L2 = addOnesColumn(L);
   dlib::matrix<double> R2 = addOnesColumn(R);

   return ccaMatrixAsVectors(L2, R2);
}