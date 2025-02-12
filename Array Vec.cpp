#include <iostream>
#include <string>


using namespace std;

void printMem(int * arr, int size) { // void printMem(int arr[], int size )
    printf("Each int is worth %lu bytes\n", sizeof(arr[0]));
    for(int i = 0; i < size; i++) {
        printf("Value :%i at Memory Location: %p\n", arr[i], arr + i);
    }
}

int main(){
// Create an array of integers that can hold 5 integers
int arr[5] = {1, 2, 3, 4, 5};
    
// Call printMem() on this array
printMem(arr, 5);

// Change the last value in the array to 500
arr[4] = 500;

// Print out the last value in the array
cout << "Last value in array: " << arr[4] << endl;

// Get the first and second address of this array
int* firstAddress = &arr[0];
int* secondAddress = &arr[1];

// Subtract the first address from the second address
ptrdiff_t byteDifference = (char*)secondAddress - (char*)firstAddress;

// Print the result in decimal
cout << "Memory difference between first and second element: " << byteDifference << " bytes" << endl;

return 0;
}
