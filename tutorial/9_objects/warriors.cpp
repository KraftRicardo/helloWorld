#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Warrior{

   private:
   string name;
   int health;
   int maxHealth;
   int attack;
   int block;

   public:
   Warrior(string name, int maxHealth, int attack, int block) : name(name), maxHealth(maxHealth), attack(attack), block(block) {
      this->health = maxHealth;
   }

   public:

   void changeHealth(int delta){
      if(health + delta < 0){
         health = 0;
      } else if(health + delta > maxHealth){
         health = maxHealth;
      } else {
         health += delta;
      }
   }

   void toString(){
      cout << getName() << " : hp = " << getHealth() << " , atk = " << getAttack() << " , block = " << getBlock() << "\n";
   }

   string getName() {
      return name;
   }

   int getHealth()  {
      return health;
   }

   int getAttack()  {
      return attack;
   }

   int getBlock()  {
      return block;
   }
};

class Battle{
   private:
   static int calcDamage(Warrior &attacker, Warrior &defender){
      int damage = attacker.getAttack() - defender.getBlock() + rand() % 4;
      return damage < 0 ? 0 : damage;
   }

   static void attack(Warrior &attacker, Warrior &defender){
      int damage = calcDamage(attacker, defender);
      cout << attacker.getName() << " attacks " << defender.getName() << " for " << damage << " damage.\n";
      defender.changeHealth(-damage);
      cout << defender.getName() << " hp = " << defender.getHealth() << "\n";
   }

   public:
   static void startFight(Warrior &w1, Warrior &w2){
      w1.toString();
      w2.toString();

      while(true){
         attack(w1, w2);
         if(w2.getHealth() == 0){
            cout << w1.getName() << " won!\n";
            break;
         }

         attack(w2, w1);
         if(w1.getHealth() == 0){
            cout << w2.getName() << " won!\n";
            break;
         }
      }
   }

};

int main() {
   srand(static_cast<uint32_t>(time(NULL)));
   Warrior thor = Warrior("Thor", 100, 30, 15);
   Warrior hulk = Warrior("Hulk", 135, 25, 10);

   Battle::startFight(thor, hulk);

   return 0;
}