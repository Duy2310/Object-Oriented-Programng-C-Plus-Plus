#ifndef RPG_H
#define RPG_H
#include <iostream>

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:

    RPG();
    RPG(string name, int health, int strength, int defense, string type);

    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    string getType() const;
    
    bool isAlive() const;
    void updateHealth (int health);
    void setSkill();
    void printAction(string, RPG opponent);
    void attack(RPG* opponent);
    void useSkill(RPG* opponent);

    private:

    string name;
    int health;
    int strength;
    int defense;
    string type;
    string skills[SKILL_SIZE];
    
}; 
#endif