#include <iostream>


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}


int main() {
    int arr[] = {3, 9, 6, 4, 7, 1, 5, 8, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    
    int result = linearSearch(arr, size, target);
    
    if (result == -1) {
        std::cout << "Element not found." << std::endl;
    } else {
        std::cout << "Element found at index: " << result << std::endl;
    }
    return 0;
}