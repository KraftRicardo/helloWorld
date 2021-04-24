#include <iostream>
#include <cstdint>
//#include <format>

using namespace std;

/*
 * comments
 * */

// TODO important
// include <format> fail?
// Can I have something like @Getter @Setter @AllArgsConstructor like in java?
// .clang-format (has CLion support) Any format recommendation?

// TODO not so important
// short cut for generate code
// short cut for generate if, for, etc. loop

// enum declaration
enum color {
    red, green, blue
};
enum color2 {
    redd, greenn = 5, bluee
};

//const declaration
#define LENGTH 10
#define WIDTH 5
const int LENGTH_2 = 100;
const int WIDTH_2 = 50;

//function declaration
void printDataTypeSizes();
void printVariables();
void printConstants();
void testSwitch(int num);
void funcWithDefaults(int num1, int num2 = 2, int num3 = 3);

//variable declaration
bool b = true; // otherwise = true, 0 = false
char c = 'x';
int i = 21;
float f = 2.0f;
double d = 3.33333;
unsigned int uI = 4;

color col1 = red;
color2 col2 = greenn;
color2 col3 = bluee;

long aa;    // may be 32 or 64 bits wide
int32_t bb; // guaranteed to be 32 bits wide
int64_t cc; // guaranteed to be 64 bits wide

int main() {
    cout << "Hello, World!";

    printDataTypeSizes();
    printConstants();
    printVariables();
    testSwitch(i);
    funcWithDefaults(5);

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
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "i = " << i << endl;
    cout << "f = " << f << endl;
    cout << "d = " << d << endl;
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


