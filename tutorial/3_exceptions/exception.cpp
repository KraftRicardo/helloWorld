#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void foo(){
   double num1;
   double num2;

   cout << "Enter number 1 : ";
   cin >> num1;
   cout << "Enter number 2 : ";
   cin >> num2;

   try{
      if(num2 == 0){
         throw "Division by zero no possible";
      } else {
         printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
      }
   } catch(const char* exp){
      cout << "Error : " << exp << "\n";
   }
}

void foo2(){
   try{
      cout << "Throwing exception\n";
      throw runtime_error("Error occurred");
      cout << "Unreachable";
   } catch(exception &exp){
      cout << "Handled exception : " << exp.what() << "\n";
   } catch(...){
      cout << "Default exception\n";
   }
}

int main(){
   foo();
   foo2();
}