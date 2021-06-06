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

   string str6 = "Cat rat mat fat pat";
   regex reg6 ("([Cr]at)");
   string owlFood = regex_replace(str6, reg6, "Owl");
   cout << owlFood << "\n\n";

   string str7 = "F.B.I. I.R.S. CIA .TEST ..TEST2 ...TEST3";
   // TODO in the tutorial \. works, why not here?
   regex reg7 ("([^ ]\\..\\..\\.)");
//   regex reg7 ("(\\.[^ ]*)");
//   regex reg7 ("(.[^ ]*)");
   printMatches2(str7, reg7);

   string str8 = "This is a\n multiline string\n that has many lines";
   regex reg8 ("\n");
   string noLBStr = regex_replace(str8, reg8, " ");
   cout << noLBStr << "\n";

   // You can also replace
   // \b : Backspace
   // \f : Form Feed
   // \r : Carriage Return
   // \t : Tab
   // \v : Vertical Tab

   return 0;
}
