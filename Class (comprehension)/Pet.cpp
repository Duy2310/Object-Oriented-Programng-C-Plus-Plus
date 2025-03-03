#include "Pet.h"

// Default constructor
Pet::Pet() {
    name = "";
    age = -1;
    owner = "";
    isHouseTrained = false;
}

// Parameterized constructor
Pet::Pet(string name, int age, string owner, bool isHouseTrained) {
    this->name = name;
    this->age = age;
    this->owner = owner;
    this->isHouseTrained = isHouseTrained;
}

// Accessor functions
string Pet::getName() const {
    return name;
}

int Pet::getAge() const {
    return age;
}

string Pet::getOwner() const {
    return owner;
}

bool Pet::getIsHouseTrained() const {
    return isHouseTrained;
}

// Mutator functions (setters)
void Pet::setName(const string name) {  // Pass by reference to avoid copy
    this->name = name;
}

void Pet::setAge(const int age) {
    this->age = age;
}

void Pet::setOwner(const string owner) {  // Pass by reference to avoid copy
    this->owner = owner;
}

void Pet::setIsHouseTrained(const bool isHouseTrained) {
    this->isHouseTrained = isHouseTrained;
}

// Print function to display pet details
void Pet::print() const {
    cout << "Pet Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Owner: " << owner << endl;
    cout << "House Trained: " << (isHouseTrained ? "Yes" : "No") << endl;
}
