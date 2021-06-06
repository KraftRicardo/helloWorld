#include <fstream>
#include <iostream>
#include <string>

#include <regex>

using namespace std;

void printMatches2(string str, regex reg){
   sregex_iterator currentMatch(str.begin(), str.end(), reg);
   sregex_iterator lastMatch;

   while(currentMatch != lastMatch){
      smatch match = *currentMatch;
      cout << match.str() << "\n";
      currentMatch++;
   }
   cout << endl;
}

int main() {

   // ----- PROBLEM -----
   // Create a Regex that matches email addresses from a list
   // 1. 1 to 20 lowercase and uppercase letters, numbers, plus ._%+-
   // 2. An @ symbol
   // 3. 2 to 20 lowercase and uppercase letters, numbers, plus .-
   // 4. A period
   // 5. 2 to 3 lowercase and uppercase letters

   string str14 = "db@aol.com m@.com @apple.com db@.com ricardo.kraft97@gmail.com";
   regex reg14 ("[\\w\\._%+-]{1,20}@[\\w.-]{2,20}\\.[a-zA-Z]{2,3}");
   printMatches2(str14, reg14);


   return 0;
}
