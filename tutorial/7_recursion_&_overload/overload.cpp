#include <iostream>
#include <valarray>

using namespace std;

double area(double radius);
double area(double height, double width);

int main() {
   cout << "Area circle (c) or rectangle (r) : ";
   char areaType;
   cin >> areaType;

   switch (areaType) {
      case 'c' :
         cout << "Enter radius : ";
         double radius;
         cin >> radius;
         cout << "Area : " << area(radius) << "\n";
         break;
      case 'r' :
         cout << "Enter height : ";
         double height;
         cin >> height;
         cout << "Enter width : ";
         double width;
         cin >> width;
         cout << "Area : " << area(width, height) << "\n";
         break;
      default:
         cout << "Please enter c or r\n";
   }

   return 0;
}

double area(double radius){
   return 3.14159 * pow(radius, 2);
}

double area(double height, double width){
   return height * width;
}


