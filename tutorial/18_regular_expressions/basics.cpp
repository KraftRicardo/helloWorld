#include <fstream>
#include <iostream>
#include <string>

#include <regex>

using namespace std;

void printMatches(string str, regex reg){
   smatch matches;
   cout << std::boolalpha;

   while(regex_search(str, matches, reg)){
      cout << "Is there a match : " << matches.ready() << "\n";
      cout << "Are there no matches : " << matches.empty() << "\n";
      cout << "Number of matches : " << matches.size() << "\n";

      cout << matches.str(1) << "\n";
      str = matches.suffix().str();
      cout << "\n";
   }
}

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
   string str = "The ape was at the apex";
   regex reg("(ape[^ ]?)");
   printMatches(str, reg);

   string str2 = "I picked the pickle";
   regex reg2("pick([^ ]+)?");
   printMatches2(str2, reg2);

   string str3 = "Cat rat mat fat pat";
   regex reg3("[crmfp]at");
   printMatches2(str3, reg3);
   regex reg4("[C-Fc-f]at");
   printMatches2(str3, reg4);
   regex reg5("[^Cr]at");
   printMatches2(str3, reg5);

   return 0;
}
