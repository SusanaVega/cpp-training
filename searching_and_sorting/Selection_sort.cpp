#include <iostream>
#include <vector>
/*
The Logic
1. Divide: Imagine the list is split into a Sorted side (left) and an Unsorted side (right).
2. Scan: Look through the entire Unsorted side to find the smallest number.
3. Swap: Swap that smallest number with the first number in the Unsorted side.
4. Repeat: Move the boundary one step to the right and repeat until the list is finished.
*/

void selectionSort(std::vector<int>& array){
    size_t size = array.size() - 1;
    int smallest{};
    int index{};
    for(size_t i = 0; i < size; i++){
        index = i;
        smallest = array[i];
        for (size_t j = i; j <= size; j++)
        {

            if (smallest > array[j]){
                smallest = array[j];
                index = j;
            }                   
        }
        if (index != i){
            array[index] = array[i];
            array[i] = smallest;
        }
    }
}


int main(){
    std::vector<int> A {29, 10, 14, 37, 13};//{5,2,1,4,3};
    selectionSort(A);
    return 0;
}