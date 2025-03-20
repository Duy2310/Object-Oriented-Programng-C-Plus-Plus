#include "RPG.h"
#include <string>
#include <iostream>

using namespace std;

void displayStats(RPG player1, RPG player2){
    cout << player1.getName() << ": "<< player1.getHealth() << " "
         << player2.getName() << ": "<< player2.getHealth() << "\n"; 
}
void gameLoop(RPG* player1, RPG* player2) {
    while (player1->isAlive() && player2->isAlive()) {
        displayStats(*player1, *player2);

        // Player 1's turn
        cout << player1->getName() << "'s turn\n";
        player1->useSkill(player2);
        cout << "----------------------------------------\n";

        if (!player2->isAlive()) break;

        // Player 2's turn
        cout << player2->getName() << "'s turn\n";
        player2->useSkill(player1);
        cout << "----------------------------------------\n";
    }
}

void displayEnd(RPG player1, RPG player2) {
    if (player1.isAlive()) {
        cout << "Wiz defeated NPC! Good game!\n";
    } else {
        cout << "NPC defeated Wiz! Good game!\n";
    }
}


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
    displayEnd(p1, p2);

    return 0;
}