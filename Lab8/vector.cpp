#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Prints the elements in the vector and their memory locations
 *
 * @param v - vector of integers (passed by const reference to prevent modification)
 */
void printMemVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << "Element: " << v[i] << " at Address: " << &v[i] << endl;
    }
}

/**
 * @brief Increments all of the elements in v by 10
 *
 * @param v - reference to a vector of integers
 */
void incVecBy10(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i] += 10;
    }
}

int main() {
    // Define a constant integer for the vector size
    const int SIZE = 5;

    // Declare a vector of integers
    vector<int> vec;

    // Populate vec with values from 100 to 104
    for (int i = 100; i < 100 + SIZE; i++) {
        vec.push_back(i);
    }

    cout << "Before Increment------------" << endl;
    printMemVec(vec);

    // Increment vector elements by 10
    incVecBy10(vec);

    cout << "After Increment------------" << endl;
    printMemVec(vec);

    // Remove the last element
    vec.pop_back();

    cout << "After Pop------------" << endl;
    printMemVec(vec);

    // Append 101 and 102 at the end of vec
    vec.push_back(101);
    vec.push_back(102);

    cout << "After Push------------" << endl;
    printMemVec(vec);

    return 0;
}
