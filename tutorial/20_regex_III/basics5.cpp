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

// [ ]   : Match what is in the brackets
// [^ ]  : Match anything not in the brackets
// ( )   : Return surrounded submatch
// .     : Match any 1 character or space
// +     : Match 1 or more of what proceeds
// ?     : Match 0 or 1
// *     : Match 0 or More
// *?    : Lazy match the smallest match
// \b    : Word boundary
// ^     : Beginning of String
// $     : End of String
// \n    : Newline
// \d    : Any 1 number
// \D    : Anything but a number
// \w    : Same as [a-zA-Z0-9_]
// \W    : Same as [^a-zA-Z0-9_]
// \s    : Same as [\f\n\r\t\v]
// \S    : Same as [^\f\n\r\t\v]
// {5}   : Match 5 of what proceeds the curly brackets
// {5,7} : Match values that are between 5 and 7 in length

int main() {

   string s1 = "The cat cat fell out of the window";
   regex r1("(\\b\\w+)\\s\\1");
   printMatches(s1, r1);

   string s2 = "<a href?'#'<b>The Link</b></a>";
   regex r2("<b>(.*?)</b>");
   string res2;
   regex_replace(back_inserter(res2), s2.begin(), s2.end(), r2, "$1");
   cout << res2 << "\n\n";

   string s3 = "412-555-1212";
   regex r3("([\\d]{3})-([\\d]{3}-[\\d]{4})");
   string res3;
   regex_replace(back_inserter(res3), s3.begin(), s3.end(), r3, "($1)$2");
   cout << res3 << "\n\n";

//   string s4 = "https://www.youtube.com https://www.google.com";
//   regex r4("(https://)(www\\.[^ ]*\\.com)");
//
//   printMatches(s4, r4);
//
//   string res4;
//   regex_replace(back_inserter(res4), s4.begin(), s4.end(), r4, "<a href='$1$2>$2</a>");
//   cout << res4 << "\n";

   string s4 = "https://www.youtube.com https://www.google.com";
   regex r4("(https?://([\\w.]+))");
   string res4;
   regex_replace(back_inserter(res4), s4.begin(), s4.end(), r4, "<a href='$1>$2</a>");
   cout << res4 << "\n\n";

   string s5 = " one two three four ";
   regex r5("(\\w+(?=\\b))");
   printMatches(s5, r5);

   string s6 = "1. Dog 2. Cat 3. Turtle ";
   regex r6("\\d\\.\\s(Dog|Cat)");
   printMatches(s6, r6);

   std::string s7 = "12345 12345-1234 1234 12346-333";
   regex r7("(\\d{5}-\\d{4}|\\d{5}(?=\\s))");
   printMatches(s7, r7);

   std::string s8 = "14125551212 4125551212 (412)5551212 412 555 1212 412-555-1212 1-412-555-1212";
   regex r8("(1?-?\\(?\\d{3}\\)?(-| )?\\d{3}(-| )?\\d{4})");
   printMatches(s8, r8);


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
