#include <ctime>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

// We open the file by providing a name and then either
// ios::app : Append to the end of the file
// ios::trunc : If the exists delete content
// ios::in : Open file for reading
// ios::out : Open file for writing
// ios::ate : Open writing and move to the end of the file


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
      }
      readFromFile.close();
   }

   return 0;
}