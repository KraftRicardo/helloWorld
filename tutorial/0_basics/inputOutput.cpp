#include <iostream>

using namespace std;

void enterTwoNumbers(){
   string sNum1, sNum2;
   cout << "Enter Number 1 : ";
   getline(cin, sNum1);
   cout << "Enter number 2 : ";
   getline(cin, sNum2);

   int i1 = stoi(sNum1);
   int i2 = stoi(sNum2);

   printf("%d + %d = %d\n", i1, i2, i1 + i2);
   printf("%d - %d = %d\n", i1, i2, i1 - i2);
   printf("%d * %d = %d\n", i1, i2, i1 * i2);
   printf("%d / %d = %d\n", i1, i2, i1 / i2);
   printf("%d %% %d = %d\n", i1, i2, i1 % i2);
}

void milesToKm(){
   string miles;
   cout << "Enter miles : ";
   getline(cin, miles);

   float i = stof(miles);

   cout << "You entered : " << i << " miles.\n";
   cout << "That converts to : " << i * 1.60934 << " km.\n";
}

int main() {
   milesToKm();
   enterTwoNumbers();
}
