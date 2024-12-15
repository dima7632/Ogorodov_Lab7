#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* createDynamicArray(int initialSize) {
    int* arr = new int[initialSize];
    return arr;
}

void expandArray(int*& arr, int& size, int k) {
    int newSize = size + k;
    int* newArr = new int[newSize];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    
    srand(time(0)); 
    for (int i = size; i < newSize; ++i) {
        newArr[i] = rand() % 100; 
    }
    
    delete[] arr;
    arr = newArr;
    size = newSize;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int initialSize = 0;
    int* arr = createDynamicArray(initialSize);
    
    for (int i = 1; i < initialSize; ++i) {
        arr[i] = 1;
    }

    printArray(arr, initialSize);

    int k = 8;
    expandArray(arr, initialSize, k);

    printArray(arr, initialSize);

    delete[] arr; 

    return 0;
}
