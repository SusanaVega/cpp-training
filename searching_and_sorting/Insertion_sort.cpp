#include <iostream>
#include <vector>
/*
The Logic
1. Start Small: Assume the first item is already "sorted."
2. Pick: Take the next unsorted item (the "key").
3. Compare and Shift: Compare the key with items in the sorted side (from right to left).
   If a sorted item is larger than the key, shift that item one position to the right.
4. Insert: Once you find the correct spot (or reach the start), drop the key into the opening.
5. Repeat: Do this for every item until the list is full.
*/

// void InsertionSort(std::vector<int>& array){
//     if(array.empty()){
//         return;
//     }
//     size_t size = array.size() - 1;
//     int key{};
//     for (size_t i = 0; i < size; i++)
//     {
//         key = array[i+1];
//         for (size_t j = i; j <= i; j--)
//         {
//             if (array[j] > key)
//             {
//                 std::swap(array[j], array[j+1]);
//                 //break;
//             }else{
//                 break;
//             }         
//         }

//     }
// }


void InsertionSort(std::vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than the key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}



int main(){
    std::vector<int> A {12, 11, 13, 5, 6}; //{10, 20, 5, 30}; //{29, 10, 14, 37, 13};{1,2,3,4,5};{7, 3, 5, 2}
    InsertionSort(A, static_cast<int>(A.size()));
    return 0;
}