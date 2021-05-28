#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct Shape {
   protected:
   double height;
   double width;

   public:
   Shape(double length) {
      height = length;
      width = length;
   }

   Shape(double h, double w){
      height = h;
      width = w;
   }

   virtual double area(){
      return height * width;
   }

   virtual ~Shape() = default;
};

struct Circle : public Shape {
   public:
   Circle(double w) : Shape(w){}

   double area(){
      return 3.14159 * pow((width / 2), 2);
   }
};

void showArea(Shape& shape){
   cout << "Area : " << shape.area() << "\n";
}

int main() {
   Shape square(10, 5);
   Circle circle(10);
   showArea(square);
   showArea(circle);

   return 0;
}