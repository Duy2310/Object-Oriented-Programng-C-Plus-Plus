#include "RPG.h"
#include <string>

// Default Constructor
RPG::RPG () {
    name = "NPC";
    health = 100;
    strength = 50;
    defense = 50;
    type = "warrior";
    skills[0]= "slash";
    skills[1]= "parry"; 
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
        skills[0] = "fire";
        skills[1] = "thunder";
    }
    else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    }
    else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    }
    else {
        skills[0] = "slash";
        skills[1] = "parry";
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
void RPG::attack(RPG* opponent) {
    int damage = strength - opponent->defense;
    int new_health = opponent->health - damage;
    opponent->updateHealth(new_health);
}
void RPG::useSkill(RPG* opponent){
    for (int i = 0; i < SKILL_SIZE; ++i){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }
    int chosen_skill_index;
    
    printf("Choose a skill to use: Enter 0 or 1\n");

    // Get user input
    cin >> chosen_skill_index;

    // Ensure input is within valid range
    if (chosen_skill_index < 0 || chosen_skill_index >= SKILL_SIZE) {
        printf("Invalid choice. Defaulting to skill 0.\n");
        chosen_skill_index = 0;
    }

    // Assign the chosen skill
    string chosen_skill = skills[chosen_skill_index];

    // Call printAction with the chosen skill and opponent
    printAction(chosen_skill, *opponent);

    // Call attack on opponent
    attack(opponent);
}
