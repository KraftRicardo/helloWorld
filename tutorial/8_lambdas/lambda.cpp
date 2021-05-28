#include <iostream>
#include <valarray>

using namespace std;

vector<int> generateRandomVector(int numberOfValues, int min, int max);
void printVec(const vector<int> v);
void printVec(const vector<double> v);

void sort(vector<int> v){
   sort(v.begin(), v.end(), [](int x, int y){return x < y;});
   cout << "Sorted : ";
   printVec(v);
}

void filter(vector<int> v){
   vector<int> evenV;
   copy_if(v.begin(), v.end(), back_inserter(evenV), [](int x){return (x % 2) == 0;});
   cout << "Filtered : ";
   printVec(evenV);
}

void sum(vector<int> v){
   int sum = 0;
   for_each(v.begin(), v.end(), [&](int x){sum += x;});
   cout << "Sum : " << sum << "\n";
}

void dividable(vector<int> v){
   int divisor;
   vector<int> v2;
   cout << "List of values dividable by : ";
   cin >> divisor;

   copy_if(v.begin(), v.end(), back_inserter(v2), [divisor](int x){return (x % divisor) == 0;});
   printVec(v2);
}

void doubleThis(vector<int> v){
   vector<double> v2;

   for_each(v.begin(), v.end(), [&](int x){v2.push_back(x * 2);});
   cout << "Double : ";
   printVec(v2);
}

void tripleVec(){
   vector<int> v1 = {1, 2, 3, 4, 5};
   vector<int> v2 = {1, 2, 3, 4, 5};
   vector<int> v3(5);

   transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int x, int y) {return x + y;});
   cout << "v3 = ";
   printVec(v3);
}

int main() {
   vector<int> v = generateRandomVector(20, 0, 50);
   cout << "Original : ";
   printVec(v);

   sort(v);
   filter(v);
   sum(v);
//   dividable(v);
   doubleThis(v);
   tripleVec();

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