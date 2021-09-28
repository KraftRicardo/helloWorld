#include "../h/cca.h"

#include <dlib/algs.h>
#include <dlib/matrix.h>
#include <dlib/statistics/cca.h>

using namespace std;
using namespace dlib;

static void testCCA();

int main() {
   cout << "Starting cca ... ";
   testDlib();
}

void testDlib() {

   // source: http://dlib.net/matrix_ex.cpp.html

   dlib::matrix<double, 3, 1> y;
   dlib::matrix<double> M(3,3);

   M = 54.2,  7.4,  12.1, 1,     2,    3, 5.9,   0.05, 1;

   y = 3.5, 1.2, 7.8;

   dlib::matrix<double> x = inv(M)*y;

   std::cout << "x: \n" << x << std::endl;
   std::cout << "y: \n" << y << std::endl;
   std::cout << "M: \n" << M << std::endl;
}

static void testCCA(){
//   matrix<double> L(3,3);
//   L = 1, 2, 3, 4, 5, 6, 7, 8, 9;
//   matrix<double> R(3,3);
//   R = 1, 2, 3, 4, 5, 6, 7, 8, 9;
//
//   matrix<double> LTrans(3,3);
//   matrix<double> RTrans(3,3);
//
//   uint64_t num_correlations = 5;
//   matrix<double, 0, 1> value = cca(L, R, LTrans, RTrans, num_correlations);
//
//   cout << "value : " << value << endl;
}