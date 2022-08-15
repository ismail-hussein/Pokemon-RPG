#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class Pokemon
{
    // defining public functions
    public:
        Pokemon();
        void setName(string input0_name);
        void setHP(int input0_hp);
        void setAttack(int input0_attack);
        void setDefense(int input0_defense);
        void setSpeed(int input0_speed);
        void setMax(int input0_max);
        void setType(string input0_type);
        void setLevel(int input0_level);
        void setMaxHP(int input);
       
        string getName() const;
        int getHP() const;
        int getAttack() const;
        int getDefense() const;
        int getSpeed() const;
        int getMax() const;
        string getType() const;
        int getLevel() const;
        int getMaxHP() const;
        
        void resetHP();
        void levelUp();
        
    // defining private variables
    private:
       string name;
       int hp;
       int attack;
       int defense;
       int speed;
       int max;
       string type;
       int level;
       int maxhp;
       
};