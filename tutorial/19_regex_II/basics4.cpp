#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>

#include <regex>

using namespace std;


void printMatches(string str, regex reg);

int main() {

   string s1 = "cat cats";
   regex r1("([cat]+s?)");
   printMatches(s1, r1);

   string s2 = "doctor doctors doctor's";
   regex r2("([odctor]+['s]{0,2})");
   printMatches(s2, r2);

   string s3 = "Just some words\nand some more\r\nand more\n";
   regex r3("[\r]?\n");
   string newS3 = regex_replace(s3, r3, " ");
   cout << newS3 << "\n";

   // *? +? {n,}? smallest match search
   string s4 = "<name>Life On Mars</name><name>Freaks and Geeks</name>";
   regex r4("<name>(.*?)</name>");
   printMatches(s4, r4);

   string s5 = "ape at the apex";
   regex r5("(\\bape\\b)");
   printMatches(s5, r5);

   // ^ for start
   string s6 = "Match everything up to @";
   regex r6("(^.*[^@])");
   printMatches(s6, r6);

   // $ for end
   string s7 = "@ Get this string";
   regex r7("([^@\\s].*$)");
   printMatches(s7, r7);

   string s8 = "206-709-3100 202-456-1111 212-832-2000";
   regex r8(".{3}-(.{8})");
   printMatches(s8, r8);

   string s9 = "My number is 904-285-3700";
   regex r9("(.{3})-(.*)-(.*)");
//   printMatches(s9, r9);
   smatch matches;
   if(regex_search(s9, matches, r9)){
      for(int i = 1; i < (int)matches.size(); i++){
         cout << matches[(uint64_t)i] << "\n";
      }
   }

   return 0;
}
void printMatches(string str, regex reg) {
   smatch matches;

   while(regex_search(str, matches, reg)){
      cout << matches.str(1) << "\n";
      str = matches.suffix().str();
   }
   cout << "\n";
}
