#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

int main(){
   //a - z : 97 - 122
   //A - Z : 65 - 90

   cout << "Enter word : ";
   string input;
   cin >> input;

   string translation;
   for(auto c : input){
      if(c != '\n'){
         translation += to_string((int)c) + " ";
      }
   }
   cout << "Translation : " << translation << "\n";

   string reTranslation;
   stringstream ss(translation);
   string word;

   while(getline(ss, word, ' ')){
      int i = stoi(word);
      char c = char(i);
      reTranslation += c;
   }
   cout << "ReTranslation : " << reTranslation << "\n";

}