#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

using namespace std;

class Pet {
    public:

//---------------Constructor----------------
    Pet();
    Pet(string name, int age, string owner, bool isHouseTrained);

//--------------Accessor--------------------
    string getName() const;
    int getAge() const;
    string getOwner() const;
    bool getIsHouseTrained() const;

    void setName (const string name) ;
    void setAge(const int age);
    void setOwner(const string owner);
    void setIsHouseTrained(const bool isHouseTrained);
    void print() const;

    private:

    string name;
    int age;
    string owner;
    bool isHouseTrained;
};
#endif