#include <iostream>
#include <valarray>

using namespace std;

vector<int> generateRandomVector(int numberOfValues, int min, int max);
void printVec(const vector<int> v);
void printVec(const vector<double> v);

void example1(){
   int age = 43;
   bool canIVote = (age >= 18) ? true : false;
   cout.setf(ios::boolalpha);
   cout << "Can Derek vote? " << canIVote << "\n";
}

void example2(){
   // TODO understand statement completely
   function<int(int)> fib = [&fib](int n) {return n < 2 ? n : fib(n-1)+ fib(n-2);};

   cout << "Fib 4 : " << fib(4) << "\n";
}

void printListOfFibs(int num){
   function<int(int)> fib = [&fib](int n) {return n < 2 ? n : fib(n-1)+ fib(n-2);};

   vector<int> listOfFibs;
   int i = 0;
   while(i < num){
      listOfFibs.push_back(fib(i));
      i++;
   }

   printVec(listOfFibs);
}

int main() {
   example1();
   example2();
   printListOfFibs(10);

   return 0;
}

vector<int> generateRandomVector(int numberOfValues, int min, int max){
   vector<int> result;
   srand(static_cast<uint32_t>(time(NULL)));
   for(int i = 0; i < numberOfValues; i++){
      result.push_back(min + rand() % (max + 1 - min));
   }
   return result;
}

void printVec(const vector<int> v){
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";
}

void printVec(const vector<double> v){
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";
}