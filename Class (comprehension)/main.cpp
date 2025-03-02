#include "Pet.h"  // Only include the header file
#include <iostream>
using namespace std;

int main() {
    // Creating a pet object using the default constructor
    Pet pet1;

    // Creating a pet object using the overloaded constructor
    Pet pet2("Taylen's cat", 3, "Duy", true);

    // Print the details of both pets using their accessor functions
    cout << "Details of pet1 (default constructor):\n";
    pet1.print();

    cout << "\nDetails of pet2 (overloaded constructor):\n";
    pet2.print();

    // Updating pet2's private variables using the mutator functions
    pet2.setName("Max");
    pet2.setAge(4);
    pet2.setOwner("Cat");
    pet2.setIsHouseTrained(true);

    // Print the updated details of pet2
    cout << "\nUpdated details of pet2 (after modifications):\n";
    pet2.print();

    return 0;
}
