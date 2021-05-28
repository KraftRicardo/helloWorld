#include <ctime>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

vector<string> stringToVector(string input, char seperator);

int main() {

   ofstream writeToFile;
   ifstream readFromFile;
   string txtToWrite = "";
   string txtFromFile = "";

   writeToFile.open("test.txt", ios_base::out | ios_base::trunc);
   if(writeToFile.is_open()){
      writeToFile << "Beginning of file\n";
      cout << "Enter data to write : ";
      getline(cin, txtToWrite);
      writeToFile << txtToWrite;
      writeToFile.close();
   }

   readFromFile.open("test.txt", ios_base::in);
   if(readFromFile.is_open()){
      while(readFromFile.good()){
         getline(readFromFile, txtFromFile);
         cout << txtFromFile << "\n";

         vector<string> words = stringToVector(txtFromFile, ' ');
         int numOfWords = (int) words.size();
         cout << "Words in line : " << numOfWords << "\n";
         int wordLength = 0;
         for(auto word : words){
            wordLength += (int) word.size();
         }
         cout << "Avg word length = " << wordLength/numOfWords << "\n";
      }
      readFromFile.close();
   }

   return 0;
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