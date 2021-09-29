#include "../h/cca.h"

#include <dlib/algs.h>
#include <dlib/matrix.h>
#include <dlib/statistics/cca.h>

using namespace std;
using namespace dlib;

static void testCCA();
void exampleMatrix();

int main() {
   cout << "Starting cca ... ";
//   testDlib();
   exampleMatrix();
}

void exampleMatrix() {
   // Let's begin this example by using the library to solve a simple
   // linear system.
   //
   // We will find the value of x such that y = M*x where
   //
   //      3.5
   // y =  1.2
   //      7.8
   //
   // and M is
   //
   //      54.2   7.4   12.1
   // M =  1      2     3
   //      5.9    0.05  1

   // First let's declare these 3 matrices.
   // This declares a matrix that contains doubles and has 3 rows and 1 column.
   // Moreover, its size is a compile time constant since we put it inside the <>.
   matrix<double, 3, 1> y;
   // Make a 3 by 3 matrix of doubles for the M matrix.  In this case, M is
   // sized at runtime and can therefore be resized later by calling M.set_size().
   matrix<double> M(3, 3);

   // You may be wondering why someone would want to specify the size of a
   // matrix at compile time when you don't have to.  The reason is two fold.
   // First, there is often a substantial performance improvement, especially
   // for small matrices, because it enables a number of optimizations that
   // otherwise would be impossible.  Second, the dlib::matrix object checks
   // these compile time sizes to ensure that the matrices are being used
   // correctly.  For example, if you attempt to compile the expression y*y you
   // will get a compiler error since that is not a legal matrix operation (the
   // matrix dimensions don't make sense as a matrix multiplication).  So if
   // you know the size of a matrix at compile time then it is always a good
   // idea to let the compiler know about it.

   // Now we need to initialize the y and M matrices and we can do so like this:
   M = 54.2, 7.4, 12.1, 1, 2, 3, 5.9, 0.05, 1;

   y = 3.5, 1.2, 7.8;

   // The solution to y = M*x can be obtained by multiplying the inverse of M
   // with y.  As an aside, you should *NEVER* use the auto keyword to capture
   // the output from a matrix expression.  So don't do this: auto x = inv(M)*y;
   // To understand why, read the matrix_expressions_ex.cpp example program.
   matrix<double> x = inv(M) * y;

   cout << "x: \n" << x << endl;

   // We can check that it really worked by plugging x back into the original equation
   // and subtracting y to see if we get a column vector with values all very close
   // to zero (Which is what happens.  Also, the values may not be exactly zero because
   // there may be some numerical error and round off).
   cout << "M*x - y: \n" << M * x - y << endl;

   // Also note that we can create run-time sized column or row vectors like so
   matrix<double, 0, 1> runtime_sized_column_vector;
   matrix<double, 1, 0> runtime_sized_row_vector;
   // and then they are sized by saying
   runtime_sized_column_vector.set_size(3);

   // Similarly, the x matrix can be resized by calling set_size(num rows, num columns).  For example
   x.set_size(3, 4); // x now has 3 rows and 4 columns.

   // The elements of a matrix are accessed using the () operator like so:
   cout << M(0, 1) << endl;
   // The above expression prints out the value 7.4.  That is, the value of
   // the element at row 0 and column 1.

   // If we have a matrix that is a row or column vector.  That is, it contains either
   // a single row or a single column then we know that any access is always either
   // to row 0 or column 0 so we can omit that 0 and use the following syntax.
   cout << y(1) << endl;
   // The above expression prints out the value 1.2

   // Let's compute the sum of elements in the M matrix.
   double M_sum = 0;
   // loop over all the rows
   for (long r = 0; r < M.nr(); ++r) {
      // loop over all the columns
      for (long c = 0; c < M.nc(); ++c) {
         M_sum += M(r, c);
      }
   }
   cout << "sum of all elements in M is " << M_sum << endl;

   // The above code is just to show you how to loop over the elements of a matrix.  An
   // easier way to find this sum is to do the following:
   cout << "sum of all elements in M is " << sum(M) << endl;

   // Note that you can always print a matrix to an output stream by saying:
   cout << M << endl;
   // which will print:
   //   54.2  7.4 12.1
   //      1    2    3
   //    5.9 0.05    1

   // However, if you want to print using comma separators instead of spaces you can say:
   cout << csv << M << endl;
   // and you will instead get this as output:
   //   54.2, 7.4, 12.1
   //   1, 2, 3
   //   5.9, 0.05, 1

   // Conversely, you can also read in a matrix that uses either space, tab, or comma
   // separated values by uncommenting the following:
   // cin >> M;
}

void testDlib() {
   // source: http://dlib.net/matrix_ex.cpp.html

   dlib::matrix<double, 3, 1> y;
   dlib::matrix<double> M(3, 3);

   M = 54.2, 7.4, 12.1, 1, 2, 3, 5.9, 0.05, 1;
   y = 3.5, 1.2, 7.8;

   auto y2 = y * 2;

   dlib::matrix<double> x = inv(M) * y;

   std::cout << "x: \n" << x << std::endl;
   std::cout << "y: \n" << y << std::endl;
   std::cout << "y2: \n" << y2 << std::endl;
   std::cout << "M: \n" << M << std::endl;
}

static void testCCA() {
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