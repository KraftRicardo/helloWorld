#include <iostream>
#include <vector>

using namespace std;

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

void editInt2(int& value){
   value += 42;
}

void editInt() {
   int i = 4;
   editInt2(i);
   cout << "i = " << i << endl;
}

// TODO wenn man das nicht machen darf, wie löst man es sonst?
int& foo() {
   int i = 42;
   return i; // ERROR: Returns dangling reference
}

void showVector(){
   std::vector<unsigned short> a;
   for (unsigned i = 0; i < 10; ++i){
      a.push_back(i + 1);
   }

   std::cout << a.size() << std::endl;// prints 10
   a.clear();
   std::cout << a.size() << std::endl;// prints 0
   a.resize(10); // a now contains 10 zeros
   std::cout << a.size() << std::endl; // prints 10

   for (unsigned i = 0; i < 10; ++i){
      a[i] = i + 1;
   }
}

void lookAtPointer(){
   int array[3] = {123, 456, 789};
//   const int* ptr = array;
   int* ptr = array;

   cout << "First elem: " << ptr[0] << endl;
}

void lookAtIntSize(){
   int array[3] = {123, 456, 789};

   std::cout << "sizeof(int) = " << sizeof(int) << std::endl;

   int* ptr0 = &array[0];
   int* ptr1 = &array[1];

   auto uptr0 = reinterpret_cast<uintptr_t>(ptr0);
   auto uptr1 = reinterpret_cast<uintptr_t>(ptr1);

   std::cout << "(ptr1 - ptr0) = " << (ptr1 - ptr0) << std::endl;
   std::cout << "(uptr1 - uptr0) = " << (uptr1 - uptr0) << std::endl;
}


int main(int argc, const char** argv) {
   showReferenceLogic();
   editInt();
   showVector();
   lookAtPointer();
   lookAtIntSize();
}

/* When to use references
   • Pass-by-reference function call semantics
   • When it is guaranteed that the referenced object will always be valid
   • When object that should be referenced is always the same
   When to use pointers
   • Only when absolutely necessary!
   • When there may not be a pointed-to object (i.e. nullptr)
   • When the 2_pointers may change to a different object
   • When 2_pointers arithmetic is desired
 * */

