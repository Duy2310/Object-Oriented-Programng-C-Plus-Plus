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
    
    RPG p1 = RPG("Wiz", 70, 45, 15, "Mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);

    return 0;
}