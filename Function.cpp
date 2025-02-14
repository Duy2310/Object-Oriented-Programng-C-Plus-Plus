#include <iostream>
#include <string>

void printMemStrings(std::string arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "String " << i << ": " << arr[i] << ", Memory Address: " << &arr[i] << std::endl;
    }
}

int main() {
    // Array of std::string containing 5 different ways to say "hello"
    std::string greetings[5] = {
        "Hello",   // English
        "Hola",    // Spanish
        "Bonjour", // French
        "Ciao",    // Italian
        "asasd"  // Japanese (Konnichiwa)
    };

    // Call the function to print memory addresses
    printMemStrings(greetings, 5);

    return 0;
}
