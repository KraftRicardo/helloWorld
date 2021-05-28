#include <ctime>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// Other Unary Operators : --, *(pointer dereference),
// -> (Member Selection), !, & (Address of), +, -

// Binary operators operate on 2 objects
// +, -, *, /, %, ==, !=, >, <, >=, <=, &&, ||,
// !, =, +=, -=, *=, /=, ^, [], &, |

class Box {
   public:
   double length;
   double width;
   double breadth;
   string boxString;

   Box() {
      length = 1;
      width = 1;
      breadth = 1;
   }

   Box(double l, double w, double b) : length(l), width(w), breadth(b) {}

   Box(const Box& box2) = default;

   Box& operator++() {
      length++;
      width++;
      breadth++;
      return *this;
   }

   operator const char*() {
      ostringstream boxStream;
      boxStream << "Box : " << length << ", " << width << ", " << breadth;
      boxString = boxStream.str();
      return boxString.c_str();
   }

   Box operator+(const Box& box2) {
      Box boxSum;
      boxSum.length = length + box2.length;
      boxSum.width = width + box2.width;
      boxSum.breadth = breadth + box2.breadth;
      return boxSum;
   }

   double operator[](int x) {
      if (x == 0) {
         return length;
      } else if (x == 1) {
         return width;
      } else if (x == 2) {
         return breadth;
      } else {
         return 0;
      }
   }

   // TODO What if I need == for reference checks? Then I cannot override the op and have to use
   // my own equals(Box other) method?
   bool operator==(const Box& box2) const {
      return ((length == box2.length) && (width == box2.width) && (breadth == box2.breadth));
   }

   bool operator<(const Box& box2) {
      return (length + width + breadth) < (box2.length + box2.width + box2.breadth);
   }

   bool operator>(const Box& box2) {
      return (length + width + breadth) > (box2.length + box2.width + box2.breadth);
   }

   void operator=(const Box& boxToCopy) {
      length = boxToCopy.length;
      width = boxToCopy.width;
      breadth = boxToCopy.breadth;
   }
};

int main() {

   Box box(10, 10, 10);
   ++box;
   cout << box << "\n";
   Box box2(5,5,5);
   cout << "Box1 + Box2 = " << box + box2 << "\n";
   cout << "Box length = " << box[0] << "\n";
   cout << boolalpha;
   cout << "box == box2? : " << (box == box2) << "\n";
   cout << "box < box2? : " << (box < box2) << "\n";
   cout << "box > box2? : " << (box > box2) << "\n";
   box = box2;
   cout << "box : " << box << "\n";

   return 0;
}