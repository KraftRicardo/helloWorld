#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


string ceasarCipher(string input, int key, bool encrypt){
   string result = "";
   if(!encrypt){
      key *= -1;
   }

   for(char c : input){
      result += static_cast<char>(c + key);
   }
   return result;
}

int main(){

   string phrase = "Make me secret";
   string encryptStr = ceasarCipher(phrase, 5, true);
   string decryptStr = ceasarCipher(encryptStr, 5, false);
   cout << "Encrypted " << encryptStr << "\n";
   cout << "Decrypted " << decryptStr << "\n";

   return 0;
}

