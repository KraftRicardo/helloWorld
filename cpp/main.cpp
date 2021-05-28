#include <cstdint>
#include <iostream>
#include "../hpp/vl4.h"

#include <fmt/core.h>

using namespace std;

// enum declaration
enum color {
   red,
   green,
   blue
};
enum color2 {
   redd,
   greenn = 5,
   bluee
};

//const declaration
#define LENGTH 10
#define WIDTH 5
const int LENGTH_2 = 100;
const int WIDTH_2 = 50;

//function declaration
static void printDataTypeSizes();

void printVariables();

void printConstants();

void testSwitch(int num);

void funcWithDefaults(int num1, int num2 = 2, int num3 = 3);

void showDifBetweenSignedAndUnsigned();

void testConditionalOperator(int num);

extern void write();

//variable declaration
bool myBool = true; // otherwise = true, 0 = false
static char myChar = 'x';
static int myInt = 21;
static float myFloat = 2.0f;
static double myDouble = 3.33333;
static unsigned int myUnsigned = 4;

static color col1 = red;
static color2 col2 = greenn;
static color2 col3 = bluee;

static long aa; // may be 32 or 64 bits wide
static int32_t bb; // guaranteed to be 32 bits wide
static int64_t cc; // guaranteed to be 64 bits wide

int count = 0;

int main() {
   cout << "Hello, World!";

   printDataTypeSizes();
   printConstants();
   printVariables();
   testSwitch(myInt);
   funcWithDefaults(5);
   showDifBetweenSignedAndUnsigned();
   write();
   testConditionalOperator(-1);
   testConditionalOperator(1);
   showReferenceLogic();

   //    fmt::print

   return 0;
}

void printDataTypeSizes() {
   cout << "#### DATA_TYPE_SIZES ####" << endl;
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
}

void printVariables() {
   cout << "#### Variables ####" << endl;
   cout << "myBool = " << myBool << endl;
   cout << "myChar = " << myChar << endl;
   cout << "myInt = " << myInt << endl;
   cout << "f = " << myFloat << endl;
   cout << "myDouble = " << myDouble << endl;
   cout << "col1 = " << col1 << endl;
   cout << "col2 = " << col2 << endl;
   cout << "col3 = " << col3 << endl;
}

void printConstants() {
   cout << "#### CONSTANTS ####" << endl;
   cout << "LENGTH =" << LENGTH << endl;
   cout << "WIDTH =" << WIDTH << endl;
   cout << "LENGTH_2 =" << LENGTH_2 << endl;
   cout << "WIDTH_2 =" << WIDTH_2 << endl;
}

void testSwitch(int num) {
   switch (num) {
      case 21:
         //write this to show the compiler that you do want to jump into the next case
         [[fallthrough]];
      case 42:
         cout << "case 42 or case 21 num = " << num << endl;
      default:
         cout << "Banana num = " << num << endl;
         break;
   }
}

void funcWithDefaults(int num1, int num2, int num3) {
   cout << "result = " << num1 + num2 + num3 << endl;
}

void showDifBetweenSignedAndUnsigned() {
   short int i; // a signed short integer
   short unsigned int j; // an unsigned short integer

   j = 50000;

   i = j;
   cout << "Dif between signed and unsigned: " << i << " " << j << endl;
}

void testConditionalOperator(int num) {
   num > 0 ? cout << "bigger" : cout << "smaller";
   cout << endl;
}

