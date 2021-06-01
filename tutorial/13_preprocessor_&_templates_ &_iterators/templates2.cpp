#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

template<typename T, typename U>
class Person{
   public:
      static int numOfPeople;
      T height;
      U weight;

      Person(T h, U w) : height(h), weight(w){
         numOfPeople++;
      }

      void getData(){
         cout << "Height : " << height << ", Weight : " << weight << "\n";
      }
};
template<typename T, typename U> int Person<T, U>::numOfPeople;

int main() {
   Person<double, int> tim = Person(1.80, 70);
   tim.getData();
   cout << "Number of people : " << tim.numOfPeople << "\n";

   Person<float, int> sonja = Person(1.5f, 50);
   Person<float, int> sonja2 = Person(1.5f, 50);

   cout << "Number of people : d " << tim.numOfPeople << "\n";
   cout << "Number of people : f " << sonja.numOfPeople << "\n";
   cout << "Number of people : f " << sonja2.numOfPeople << "\n";

   return 0;
}
