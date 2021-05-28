#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void printTreeLine(int spaces, int hashes){

   for(int i = 0; i < spaces; i++){
      cout << " ";
   }

   for(int i = 0; i < hashes; i++){
      cout << "#";
   }
   cout << "\n";
}

void printTree(){
   int height;

   cout << "How tall is the tree : ";
   cin >> height;

   int spaces = height - 1;
   int hashes = 1;

   for(int i = 0; i < height; i++){
      printTreeLine(spaces - i, hashes + i * 2);
   }
}

void guessNum(){
   srand((uint32_t)time(NULL));
   int secretNum = rand() % 11;
   int guess = 0;

   do{
      cout << "Guess the number : ";
      cin >> guess;
      if(guess > secretNum){
         cout << "To big\n";
      }
      if(guess < secretNum){
         cout << "To small\n";
      }
   } while (guess != secretNum);

   cout << "Success!";
}

int main(){
   printTree();
   guessNum();
}

