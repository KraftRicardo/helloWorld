#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> generateRandomVector(int numberOfValues, int min, int max);
void bubbleSort(vector<int> &vec);

int main(){
   vector<int> v = generateRandomVector(20, 5, 24);
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";

   bubbleSort(v);
   for(auto i : v){
      cout << i << " ";
   }
   cout << "\n";

   return 0;
}

void bubbleSort(vector<int> &vec){
   int i = (int)vec.size() - 1;
   while(i >= 1){
      int j = 0;
      while(j < i){
         if(vec[j] >= vec[j+1]){
            int temp = vec[j+1];
            vec[j+1] = vec[j];
            vec[j] = temp;
         }
         j += 1;
      }
      i -= 1;
   }

}

vector<int> generateRandomVector(int numberOfValues, int min, int max){
   vector<int> result;
   srand(static_cast<uint32_t>(time(NULL)));
   for(int i = 0; i < numberOfValues; i++){
      result.push_back(min + rand() % (max + 1 - min));
   }
   return result;
}