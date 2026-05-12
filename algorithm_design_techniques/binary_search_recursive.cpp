#include <iostream>
#include <vector>
//#include "Reader.h"

// int binarySearch(std::vector<int>& data, int index, size_t size, int target){
//     int left{0};
//     int right{static_cast<int>(size)};
//     int mid {(left + (right - left)/2)};
//     do{
//         mid = (left + (right - left)/2);
//         if (target == data[mid]){
//             return mid;
//         }
//         if (target < data[mid]){
//                 right = mid -1;
//         } else{
//                 left = mid + 1;
//             }
//     } while (left <= right);
//     return -1;
// }

int binarySearch(std::vector<int> array, int left, int right, int target ) {
    int mid = left + (right - left) / 2;
    if (right < left)
        return -1;
    if (target == array[mid])
        return mid;
    else if (target < array[mid])
        return binarySearch(array, left, mid - 1, target);
    else
        return binarySearch(array, mid + 1, right, target);
}


int main(){
    int target {398};
    std::vector<int> data {-3, 0, 5, 16, 84, 107, 398, 721};//{-3, 0, 5, 16, 84, 107, 398, 721} - {24, 38, 40, 55, 69, 72, 85, 93} - {-30, -20, -10, 0, 10, 20, 30, 40}
    int result = binarySearch(data, 0, data.size() -1,target);

    // Print the result
    if (result != -1) {
        std::cout << "Element " << target << " is located at index: " << result << std::endl;
    } else{
        std::cout << "Element not found" << std::endl;
    }
    return 0;
}