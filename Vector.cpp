#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector of doubles with 5 values
    vector<int> vec = {1, 2, 3, 4, 5};

    // Add values 6 and 7 using push_back
    vec.push_back(6);
    vec.push_back(7);

    // Print the number of elements in the vector
    cout << "Number of elements in the vector: " << vec.size() << endl;

    // Remove the last element in the vector
    vec.pop_back();

    // Print the number of elements again
    cout << "Number of elements in the vector after pop_back: " << vec.size() << endl;


    return 0;
}
