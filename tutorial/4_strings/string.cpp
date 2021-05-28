#include <iostream>
#include <vector>

using namespace std;

void example1(){
   vector<string> vec(10);

   string s = "I'm a string";
   vec[0] = s;

   cout << "s = " << s << "\n";
   cout << "vec[0] = " << vec[0] << "\n";

   s = "new Text";

   cout << "s = " << s << "\n";
   cout << "vec[0] = " << vec[0] << "\n";

   vec[0] = "blabla";

   cout << "s = " << s << "\n";
   cout << "vec[0] = " << vec[0] << "\n";
}

void example2(){
   vector<string> vec(10);

   string s = "I'm a string";
   vec[0] = s;
   cout << s.front() << " " << s.back() << "\n";

   string s2 = s;
   vec[1] = s2;

   string s3 = string(s, 4);
   vec[2] = s3;

   string s4 = string(5, 'x');
   vec[3] = s4;

   vec[4] = s.append(" and you're not");

   s += " and you are not";
   s.append(s, 34, 37);
   cout << "s : " << s << "\n";

   vec[5] = s;

   s.erase(13, s.length() - 1);
   vec[6] = s;


   for(auto x : vec){
      cout << x << "\n";
   }
}

void example3(){
   string str = "I'm a string";

   if(str.find("string") != string::npos){
      cout << "1st index " << str.find("string") << "\n";
   }

   cout << "Substring " << str.substr(6, 6) << "\n";

   reverse(str.begin(), str.end());
   cout << "Reverse " << str << "\n";

   string str2 = "I'm a string";

   transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
   cout << "Upper " << str2 << "\n";
   transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
   cout << "Lower " << str2 << "\n";

   //a - z : 97 - 122
   //A - Z : 65 - 90

   char c = 'A';
   int i = c;

   cout << "c : " << c << "\n";
   cout << "i : " << i << "\n";
   cout << "cast : " << (int)'A' << "\n";
   string s = to_string(1+2);
   cout << "String " << s << "\n";
}

int main(){
//   example1();
//   example2();
   example3();
}