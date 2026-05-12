#include <iostream>



int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid; // Target found, return index
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
return -1; // Target not found
}







int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    
    int result = binarySearch(arr, size, target);
    
    if (result == -1) {
        std::cout << "Element not found." << std::endl;
    } else {
        std::cout << "Element found at index: " << result << std::endl;
    }
    return 0;
}
