#include <iostream>
struct MyObject {
   friend void showFriendAccess(MyObject& f);

   private:
   int16_t i1;
   int32_t i2;
   int64_t i3;

   protected:
   double d;

   public:
   std::string name;
   int a;
   int b;
   int c;
   float f;
   bool myBool;

   static void resetObjValues(MyObject o){
      o.print();
      o.reset();
      o.print();
   };

   void print(){
      std::cout << name << ": a = " << " b = " << b << " c = " << c
                << " f = " << f << " myBool = " << myBool
                << " i1 = " << i1 << " i2 = " << i2 << " i3 = " << i3
                << std::endl;
   }

   void reset(){
      a = 0;
      b = 0;
      c = 0;
      f = 0;
      myBool = 0;
   };

   // const-qualified non-static member function
   void cfoo() const {
      std::cout << "Called cfoo" << std::endl;
   }

   // ref-qualified non-static member function
   void rfoo() & {
      std::cout << "Called rfoo" << std::endl;
   };

   // ############# Constructor
   // default - constructor
   MyObject(){
      std::cout << "Creating default MyObject MyObject." << std::endl;
   }

   // 1 argument constructor (make this explicit)
   explicit MyObject(int i) {
      std::cout << "Creating explicit MyObject MyObject." << std::endl;
   }

   // normal constructor
   MyObject(std::string name, int a, int b, int c, float f, bool myBool, int16_t i1, int16_t i2, int16_t i3) :
      name(name), a(a), b(b), c(c), f(f), myBool(myBool), i1(i1), i2(i2), i3(i3) {
   }

   // copy constructor
   MyObject(const MyObject& other) : name(other.name), a(other.a), b(other.b), c(other.c), f(other.f), myBool(other.myBool){
      i1 = 0;
      i2 = 0;
      i3 = 0;
      std::cout << "Copying MyObject " << std::endl;
   }

   MyObject& operator = (const MyObject& other){
      name = other.name;
      a = other.a;
      b = other.b;
      c = other.c;
      f = other.f;
      myBool = other.myBool;
      i1 = 0;
      i2 = 0;
      i3 = 0;
   }


   // Destructor
   ~MyObject(){
      std::cout << "Calling Destructor" << std::endl;
   }

   bool operator==(const MyObject& f); // Overloaded operator ==
}__attribute__((aligned(32))) __attribute__((packed));

void showFriendAccess(MyObject& f){
   std::cout << "Before: MyPrivateShort =  " << f.i1;
   f.i1++;
   std::cout << " After: MyPrivateShort =  " << f.i1 << std::endl;
}

int main(int argc, const char** argv) {
   std::cout << "Started main5 ... " << std::endl;

   MyObject c = MyObject("obj_c", 1, 2, 3, 4.5f, 0, -1, -2, -3);

   MyObject d = MyObject(c);
   d.name = "obj_d";

   MyObject e = c;
   e.name = "obj_e";

   c.print();
   d.print();
   e.print();

   showFriendAccess(c);
}