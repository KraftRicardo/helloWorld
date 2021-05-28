#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
typedef long long int  ull;

void findEven(ull start, ull end, ull* evenSum){
   for(ull i = start; i <= end; i++){
      if(!(i & 1)){
         *(evenSum) += i;
      }
   }
}

void findOdd(ull start, ull end, ull* oddSum){
   for(ull i = start; i <= end; i++){
      if(i & 1){
         *(oddSum) += i;
      }
   }
}

void calc(bool useThreads){
   if(useThreads){
      cout << "(with threads)";
   } else {
      cout << "(without threads)";
   }
   cout << "\n";

   ull start = 0;
   ull end = 1900000000;
   ull oddSum = 0;
   ull evenSum = 0;

   int64_t startTime = clock();

   if(useThreads){
      thread t1(findEven, start, end, &evenSum);
      thread t2(findOdd, start, end, &oddSum);
      t1.join();
      t2.join();
   } else {
      findEven(start, end, &evenSum);
      findOdd(start, end, &oddSum);
   }

   int64_t endTime = clock();
   cout << "Execution time : " << double (endTime - startTime) / CLOCKS_PER_SEC;

   cout << "Even : " << evenSum << "\t";
   cout << "Odd : " << oddSum << endl;
}

void calc2(bool useThreads){
   if(useThreads){
      cout << "(with threads)";
   } else {
      cout << "(without threads)";
   }
   cout << "\n";

   ull start = 0;
   ull end = 1900000000;
   ull oddSum = 0;
   ull evenSum = 0;

   std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

   if(useThreads){
      thread t1(findEven, start, end, &evenSum);
      thread t2(findOdd, start, end, &oddSum);
      t1.join();
      t2.join();
   } else {
      findEven(start, end, &evenSum);
      findOdd(start, end, &oddSum);
   }

   std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
   std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(endTime - begin).count() << "[µs]" << std::endl;
   std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (endTime - begin).count() << "[ns]" << std::endl;

   cout << "Even : " << evenSum << "\t";
   cout << "Odd : " << oddSum << endl;
}

int main(){
//   calc(true);
//   calc(false);

   calc2(true);
   calc2(false);

   return 0;
}