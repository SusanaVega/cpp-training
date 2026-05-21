#include <iostream>
#include <vector>
/*
The LogicCompare: 
1. Look at the first two numbers.
2. Swap: If the left number is bigger than the right, swap them.
3. Move: Move to the next pair (2nd and 3rd numbers) and repeat.
3. Repeat: Once you reach the end of the list, the largest number is "locked" at the back. Start over from the beginning for the remaining numbers.



*/

void bubbleSort(std::vector<int>& array){
    if(array.empty()){
        return;
    }
    size_t size = array.size() - 1;
    bool swapped {};
    for (size_t i = 0; i < size; i++)
    {
        swapped= false;
        for (size_t j = 0; j < size; j++)
        {
            if (array[j] > array[j+1])
            {
                std::swap(array[j], array[j+1]);
                swapped = true;
                //break;
            }            
        }
        // If no two elements were swapped by inner loop, then break
        if(!swapped){
            break;
        }
    }
}


int main(){
    std::cout << "start" <<std::endl;
    std::vector<int> A {42,3325,18,1601,63,7,18}; //{1,2,3,4,5}; 
    bubbleSort(A);
    return 0;
}