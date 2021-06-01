#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include <memory>
#include <stdio.h>

using namespace std;

class Pizza{
   public:
   virtual void MakePizza() = 0;
   virtual ~Pizza() = default;
};

class NYStyleCrust{
   public:
   string AddIngredient(){
      return "Crust so thin you can see through it \n\n";
   }
};

class DeepDishCrust{
   public:
   string AddIngredient(){
      return "Super Awesome Chicago Deep \n\n";
   }
};

template<typename T>
class LotsOfMeat : public T{
   public:
   string AddIngredient(){
      return "Lots of meat, " + T::AddIngredient();
   }
};

template<typename T>
class Vegan : public T{
   public:
   string AddIngredient(){
      return "Vegan Cheese, Veggies, " + T::AddIngredient();
   }
};

template <typename T>
class MeatNYStyle : public T, public Pizza{
   public:
   void MakePizza(){
      cout << "Meat NY Style Pizza : " << T::AddIngredient();
   }
};

template <typename T>
class VeganDeepDish : public T, public Pizza{
   public:
   void MakePizza(){
      cout << "Vegan Deep Dish : " << T::AddIngredient();
   }
};

int main() {
   vector<unique_ptr<Pizza>> pizzaOrders;
   // TODO Why does work and without parenthesis? Difference?
   pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>);
   pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());

   pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>);

   for(auto &pizza :pizzaOrders){
      pizza -> MakePizza();
   }

   return 0;
}
