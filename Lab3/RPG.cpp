#include "RPG.h"
#include <string>
#include <iostream>

// Default Constructor
RPG::RPG () {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skill[0]= "slash";
    skill[1]= "parry"; 
}

// Parameterized constructor
RPG::RPG (string name, int health, int strength, int defense, string type) {

    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkill();
}

string RPG::getName() const{
    return name;
}
int RPG::getHealth() const {
    return health;
}
int RPG::getStrength() const {
    return strength;
}
int RPG::getDefense() const {
    return defense;
}
string RPG::getType() const {
    return type;
}
/**
 * @brief sets the skills base on the RPG's role
 * 
 */
void RPG::setSkill() {
    if (type == "mage") {
        skill[0] = "fire";
        skill[1] = "thunder";
    }
    else if (type == "thief") {
        skill[0] = "pilfer";
        skill[1] = "jab";
    }
    else if (type == "archer") {
        skill[0] = "parry";
        skill[1] = "crossbow_attack";
    }
    else {
        skill[0] = "slash";
        skill[1] = "parry";
    }
}
void RPG::printAction(string skill, RPG opponent) {
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(),opponent.getName().c_str());
}

void RPG::updateHealth(int new_health){
    this->health = new_health;
}
bool RPG::isAlive() const {
    return this->health > 0;
}
