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

int getRandom(int max){
   srand(static_cast<unsigned int>(time(NULL)));
   return rand() % max;
}

string getTime(){
   auto nowTime = chrono::system_clock::now();
   time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
   return ctime(&sleepTime);
}

double acctBalance = 100;
mutex acctLock;

void getMoney(int threadID, double withdrawal){
   lock_guard<mutex> lock(acctLock);
   this_thread::sleep_for(chrono::seconds(1));
   cout << threadID << " tries to withdrawal $ " << withdrawal << " on " << getTime() << endl;

   if((acctBalance - withdrawal) >= 0){
      acctBalance -= withdrawal;
      cout << "New account balance is $" << acctBalance << endl;
   } else {
      cout << "Not enough money in account\n";
      cout << "Current balance is $" << acctBalance << endl;
   }
//   acctLock.unlock();
}

int main(){

   thread threads[10];
   for(int i = 0; i < 10; i++){
      threads[i] = thread(getMoney, i, 15);
   }
   for(auto &thread : threads){
      thread.join();
   }

   return 0;
}