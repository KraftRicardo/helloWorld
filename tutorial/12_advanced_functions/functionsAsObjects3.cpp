#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

using namespace std;

vector<char> generateList(vector<char> possibleValues, int numOfValuesToGenerate);
int getNumberOfMatches(vector<char> vector, char letter);

int main() {
   vector<char> possibleValues{'H', 'T', 'Z'};
   vector<char> throws = generateList(possibleValues, 100);

   cout << "Number of heads : " << getNumberOfMatches(throws, 'H') << "\n";
   cout << "Number of tails : " << getNumberOfMatches(throws, 'T') << "\n";
   cout << "Number of z : " << getNumberOfMatches(throws, 'Z') << "\n";

   return 0;
}

vector<char> generateList(vector<char> possibleValues, int numOfValuesToGenerate) {
   srand((uint) time(NULL));
   vector<char> result;

   for(int i = 0; i < numOfValuesToGenerate; i++){
      result.push_back(possibleValues[(uint64_t) rand() % possibleValues.size()]);
   }
   return result;
}

int getNumberOfMatches(vector<char> vector, char letter) {
   int result = 0;
   for(char c : vector){
      if(c == letter){
         result++;
      }
   }
   return result;
}
