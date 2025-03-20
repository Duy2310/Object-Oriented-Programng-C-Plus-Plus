#include "RPG.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    RPG RPG1; // Default constructor
    RPG Mage("Henry", 100,70,80,"mage");

    //--------------Default constructor---------
    cout <<"Default constructor";
    cout <<"Name: " << RPG1.getName() << endl;
    cout <<"Health: " << RPG1.getHealth() << endl;
    cout <<"Strength: " << RPG1.getStrength() << endl;
    cout <<"Defense: " << RPG1.getDefense() << endl;
    cout <<"Type: " << RPG1.getType() << endl;
    cout <<"Alive: " << (RPG1.isAlive() ? "YES" : "NO") << endl;
    cout << endl;

    //--------------Overload constructor----------
    cout <<"Overload constructor";
    cout <<"Name: " << Mage.getName() << endl;
    cout <<"Health: " << Mage.getHealth() << endl;
    cout <<"Strength: " << Mage.getStrength() << endl;
    cout <<"Defense: " << Mage.getDefense() << endl;
    cout <<"Type: " << Mage.getType() << endl;
    cout <<"Alive: " << (Mage.isAlive() ? "YES" : "NO") << endl;
    cout << endl;

    cout << "Update Henry's health to 50" << endl;
    Mage.updateHealth(50);
    cout << "Henry's new health: " << Mage.getHealth() << endl;
    cout << "Alive: " << (Mage.isAlive() ? "YES" : "NO") << endl;
    cout << endl;

    cout << "Update Henry's health to 0" << endl;
    Mage.updateHealth(0);
    cout << "Henry's new health: " << Mage.getHealth() << endl;
    cout << "Alive: " << (Mage.isAlive() ? "YES" : "NO") << endl;

    RPG p1 = RPG("Wiz", 70, 45, 15, "Mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayStat(p1, p2);

    return 0;
}