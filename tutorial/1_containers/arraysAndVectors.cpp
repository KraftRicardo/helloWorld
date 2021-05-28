#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void myArrays(){
   int arr[10] = {1};
   cout << "1st value : " << arr[0] << "\n";
   int arr2[10] = {1, 2, 3};
   cout << "1st value : " << arr2[0] << "\n";
   int arr3[5] = {8, 9};

   cout << "1st value : " << arr3[0] << "\n";
   arr3[0] = 7;
   cout << "1st value : " << arr3[0] << "\n";

   cout << "Array size : " << sizeof(arr3) / sizeof(*arr3) << "\n";

   int arr4[2][2][2] = {{{1,2}, {3,4}}, {{5, 6}, {7,8}}};
   cout << "2nd value : " << arr4[1][1][1] << "\n";
}

void myVectors(const string &sentence){

   vector<string> vecsWords;
   stringstream ss(sentence);
   string individualString;
   char cSpace = ' ';

   while(getline(ss, individualString, cSpace)){
      vecsWords.push_back(individualString);
   }

   for(const auto &s : vecsWords){
      cout << s << "\n";
   }
}

int main(){
   myArrays();
   myVectors("This is a random string.");
}