#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct Shape {
   virtual double area() = 0;

   virtual ~Shape() = default;
};

struct Circle : public Shape {
   protected:
   double width;

   public:
   Circle(double w) : width(w){}

   double area() override{
      return 3.14159 * pow((width / 2), 2);
   }
};

struct Rectangle : public Shape {
   protected:
   double height;
   double width;

   public:
   Rectangle(double h, double w) : height(h), width(w){}

   double area() override final{
      return height * width;
   }
};

void showArea(Shape& shape){
   cout << "Area : " << shape.area() << "\n";
}

int main() {
   Rectangle rectangle(10, 5);
   Circle circle(10);
   showArea(rectangle);
   showArea(circle);

   return 0;
}