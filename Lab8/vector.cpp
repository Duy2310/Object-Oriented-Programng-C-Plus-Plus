#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Prints the elements in the vector and their memory locations
 *
 * @param v - vector of integers
 */
void printMemVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout<< "Element: " << v[i] << " at Address: " << &v[i] << endl;
    }
}

/**
 * @brief Increments all of the elements in v by 10
 *
 * @param v - address to a vector of integers
 */
void incVecBy10(vector<int>& v) {
    
    for (size_t i = 0; i < v.size(); i++) {
        v[i] += 10;
    }
}

int main() {
    // Create a constant integer called SIZE that is of value 5
    const int SIZE = 5;

    // Create a vector of integers called vec that can hold up to 5 elements
    vector<int> vec;

    // Use a for loop to populate vec with the values 100 to 104
    for (int i = 100; i < 100 + SIZE; i++) {
        vec.push_back(i);
    }
    
    cout << "Before Increment------------\n";
    printMemVec(vec);

    // Call incVecBy10(...) on vec
    incVecBy10(vec);

    printf("After Increment------------\n");
    printMemVec(vec);

    // Remove last element of vec
    vec.pop_back();

    printf("After Pop------------\n");
    printMemVec(vec);

    // Append 101 and 102 at the end of vec
    vec.push_back(101);
    vec.push_back(102);

    printf("After Push------------\n");
    printMemVec(vec);

    return 0;
}
