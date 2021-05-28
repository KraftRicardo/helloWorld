#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct Shape {
   private:
   int id;

   public:
   double length;
   double width;

   // TODO implicit / explicit key word
   Shape(double length = 1, double width = 1) : length(length), width(width) {}

   double area() {
      return length * width;
   }
};

struct Circle : Shape {
   Circle(double width) {
      this->width = width;
   }

   double area() {
      return 3.14159 * pow((width / 2), 2);
   }
};

int main() {
   Shape shape(10, 10);
   cout << "Squared area : " << shape.area() << "\n";
   Circle circle(10);
   cout << "Circle area : " << circle.area() << "\n";
   Shape rectangle{10, 15};
   cout << "Rectangle area : " << rectangle.area() << "\n";

   return 0;
}