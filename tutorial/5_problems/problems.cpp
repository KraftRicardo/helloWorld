#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void example1();
vector<string> stringToVector(string input, char seperator);
string vectorToString(vector<string> input, char seperator);

void example2();
string trimWhiteSpace(string input);

void example3();
vector<uint64_t> findSubStringMatches(string phrase, string subString);

void example4();
string replaceAllSubStrings(string phrase, string oldString, string newString);

void example5();


int main(){
//   example1();
//   example2();
//   example3();
//   example4();
   example5();

   return 0;
}

void example5(){
   char letterZ = 'z';
   char num3 = '3';
   char aSpace = ' ';

   cout << "Is z a letter or number " << isalnum(letterZ) << "\n";
   cout << "Is z a letter " << isalpha(letterZ) << "\n";
   cout << "Is z uppercase " << isupper(letterZ) << "\n";
   cout << "Is z lowercase " << islower(letterZ) << "\n";
   cout << "Is 3 a number " << isdigit(num3) << "\n";
   cout << "Is space a space " << isspace(aSpace) << "\n";
}

void example4(){
   cout << replaceAllSubStrings("to know or not to know", "know", "be") << "\n";
}

string replaceAllSubStrings(string phrase, string oldString, string newString){
   vector<uint64_t> matches = findSubStringMatches(phrase, oldString);
   if(!matches.empty()){
      int delta = (int)newString.size() - (int)oldString.size();

      int wordsReplaced = 0;
      for(auto j : matches){
         uint64_t index = j + static_cast<uint64_t>(wordsReplaced * delta);
         phrase.replace(index, oldString.size(), newString);
         wordsReplaced++;
      }
   }
   return phrase;
}

void example3(){
//   string s = "to be or not to be";
   string s = "to know or not to know";
   vector<uint64_t> v = findSubStringMatches(s, "know");
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";
}

vector<uint64_t> findSubStringMatches(string phrase, string subString){
   vector<uint64_t> result;
   uint64_t index = phrase.find(subString, 0);
   while(index != string::npos){
      result.push_back(index);
      index = phrase.find(subString, index + 1);
   }
   return result;
}

void example2(){
   string sentence = "     just a string    \t";
   sentence = trimWhiteSpace(sentence);
   cout << "*" << sentence << "*\n";
}

string trimWhiteSpace(string input){
   string whiteSpaces(" \t\f\n\r");
   input.erase(0, input.find_first_not_of(whiteSpaces)); // front
   input.erase(input.find_last_not_of(whiteSpaces) + 1); // back
   return input;
}

void example1(){
   string word = "Hello, how are you?";
   vector<string> v = stringToVector(word, ' ');
   for(string s : v){
      cout << s << ' ';
   }
   cout << "\n";

   string newWord = vectorToString(v, ' ');
   cout << "newWord : " << newWord << "\n";
}

vector<string> stringToVector(string input, char seperator){
   vector<string> result;
   stringstream ss(input);
   string buffer;

   while(getline(ss, buffer, seperator)){
      result.push_back(buffer);
   }
   return result;
}

string vectorToString(vector<string> input, char seperator){
   string result;
   for(string s : input){
      if(s == input.back()){
         result += s;
      } else {
         result += s + seperator;
      }
   }
   return result;
}