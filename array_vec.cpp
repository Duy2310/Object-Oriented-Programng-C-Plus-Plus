#include <iostream>
#include <string>

using namespace std;

void printMem(int* arr, int size) {
    printf("Each int is worth %lu bytes\n", sizeof(arr[0]));
    for (int i = 0; i < size; i++) {
        printf("Value: %i at Memory Location: %p\n", arr[i], arr + i);
    }
}


int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // Step 2: Call printMem() to print memory addresses
    printMem(arr, 5);

    // Step 3: Change the last value in the array to 500
    arr[4] = 500;

    // Step 4: Print out the last value after modification
    printf("Last value in the array after modification: %d\n", arr[4]);
    
    return 0;

}
