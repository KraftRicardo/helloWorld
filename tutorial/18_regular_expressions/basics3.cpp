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

   // \d [0-9]
   // \D [^0-9]
   string str9 = "12345";
   regex reg9 ("\\d");
   printMatches2(str9, reg9);

   string str10 = "123 12345 1234567 23456789";
   regex reg10 ("\\d{5,7}");
   printMatches2(str10, reg10);

   // \w [a-zA-Z0-9]
   // \W [^a-zA-Z0-9]
   string str11 = "412-867-5309";
   regex reg11 ("\\w{3}-\\w{3}-\\w{4}");
   printMatches2(str11, reg11);

   // \s [\f\n\r\t\v]
   // \S [^\f\n\r\t\v]
   string str12 = "Ricardo Kraft";
   regex reg12 ("\\w{2,20}\\s\\w{2,20}");
   printMatches2(str12, reg12);

   string str13 = "a ab abc abcd";
   regex reg13 ("a[a-z]+");
   printMatches2(str13, reg13);

   return 0;
}
