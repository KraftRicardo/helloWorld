#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Animal {
   private:
   static int numOfAnimals;

   string name;
   double height;
   double weight;

   public:
   string& getName() {
      return name;
   }
   void setName(string name) {
      this->name = name;
   }
   double getHeight() {
      return height;
   }
   void setHeight(double height) {
      this->height = height;
   }
   double getWeight() {
      return weight;
   }
   void setWeight(double weight) {
      this->weight = weight;
   }

   void setAll(string, double, double);
   Animal(string, double, double);
   Animal();
   ~Animal();

   static int getNumOfAnimals(){
      return numOfAnimals;
   }
   void toString();
};

int Animal::numOfAnimals = 0;

void Animal::setAll(string name, double height, double weight){
   this->name = name;
   this->height = height;
   this->weight = weight;
   Animal::numOfAnimals++;
}

Animal::Animal(string name, double height, double weight){
   this->name = name;
   this->height = height;
   this->weight = weight;
   Animal::numOfAnimals++;
}

Animal::Animal(){
   this->name = "";
   this->height = 0;
   this->weight = 0;
   Animal::numOfAnimals++;
}

Animal::~Animal(){
   cout << "Animal " << this->name << " destroyed\n";
}

void Animal::toString() {
   cout << this->name << " is " << this->height << " cm tall and weighs " << this->weight << " kg.\n";
}

class Dog: public Animal{
   private:
   string sound = "Woof";

   public:
   void makeSound(){
      cout << "The dog " << this->getName() << " says " << this->sound << "\n";
   }

   Dog(string, double, double, string);

   Dog(): Animal(){};

   void toString();
};

Dog::Dog(string name, double height, double weight, string sound) : Animal(name, height, weight){
   this->sound = sound;
}

void Dog::toString() {
   cout << this->getName() << " is " << this->getHeight() << " cm tall and weighs " << this->getWeight() << " kg and says " << sound << "\n";
}

int main() {

   Animal fred;
   fred.toString();
   fred.setHeight(33);
   fred.setWeight(10);
   fred.setName("Fred");
   fred.toString();

   Animal tom("Tom", 36, 15);
   tom.toString();

   Dog spot("Spot", 38, 16, "Wooooof");
   spot.toString();

   cout << "Number of animals = " << Animal::getNumOfAnimals() << "\n";

   return 0;
}