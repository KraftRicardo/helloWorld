#include "../hpp/vl4.h"

using namespace std;

void editInt2(int& value){
   value += 42;
}

void showReferenceLogic() {
   unsigned i = 10;
   unsigned j = 42;
   unsigned& r = i; // r is an alias for myInt

   r = 21; // modifies myInt to be 21
   r = j; // modifies myInt to be 42

   i = 123;
   j = r; // modifies j to be 123

   cout << "i = "<< i << " j = " << j << " r = " << r << endl;
}

void editInt() {
   int i = 4;
   editInt2(i);
   cout << "i = " << i << endl;
}