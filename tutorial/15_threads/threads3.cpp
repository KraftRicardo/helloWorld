#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>



using namespace std;

mutex vectLock;
vector<uint64_t> primeVect;

void findPrimes(uint64_t start, uint64_t end){
   for(uint64_t x = start; x <= end; x++){
      for(uint64_t y = 2; y < x; y++){
         if((x % y) == 0){
            break;
         } else if((y + 1) == x){
            vectLock.lock();
            primeVect.push_back(x);
            vectLock.unlock();
         }
      }
   }
}

void findPrimesWithThreads(uint64_t start, uint64_t end, uint64_t numThreads){
   vector<thread> threadVect;
   uint64_t threadSpread = (end - start) / numThreads;
   uint64_t newEnd = start + threadSpread - 1;
   for(uint64_t x = 0; x < numThreads; x++){
      threadVect.emplace_back(findPrimes, start, newEnd);
      start += threadSpread;
      newEnd += threadSpread;
   }
   for(auto &t : threadVect){
      t.join();
   }

   // TODO vector zusammenfassen
}

int main(){
   int64_t startTime = clock();
   findPrimesWithThreads(1, 100000, 1);
   int64_t endTime = clock();
   cout << "Execution time : (1)" << double (endTime - startTime) / CLOCKS_PER_SEC << endl;

   startTime = clock();
   findPrimesWithThreads(1, 100000, 2);
   endTime = clock();
   cout << "Execution time : (2)" << double (endTime - startTime) / CLOCKS_PER_SEC << endl;

   startTime = clock();
   findPrimesWithThreads(1, 100000, 3);
   endTime = clock();
   cout << "Execution time : (3)" << double (endTime - startTime) / CLOCKS_PER_SEC << endl;

   startTime = clock();
   findPrimesWithThreads(1, 100000, 4);
   endTime = clock();
   cout << "Execution time : (4)" << double (endTime - startTime) / CLOCKS_PER_SEC << endl;

//   for(auto i : primeVect){
//      cout << i << "\n";
//   }

   return 0;
}