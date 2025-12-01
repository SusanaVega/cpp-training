#include <iostream>
/*
Add two optimizations to the bubble sort algorithm you wrote in the previous quiz question:
- Notice how with each iteration of bubble sort, the biggest number remaining gets bubbled to the end of the array. 
  After the first iteration, the last array element is sorted. 
  After the second iteration, the second to last array element is sorted too. And so on… With each iteration, 
  we don’t need to recheck elements that we know are already sorted. 
  **Change your loop to not re-check elements that are already sorted.

- If we go through an entire iteration without doing a swap, then we know the array must already be sorted. 
  Implement a check to determine whether any swaps were made this iteration, and if not, terminate the loop early. 
  If the loop was terminated early, print on which iteration the sort ended early.

*/


int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    int lenght {static_cast<int>(std::size(array))};
    //  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable
    bool flag{false};
    for(int i {0}; i < lenght-1; ++i)
    {
        //flag to terminate the loop early
        flag = false;
        for (int j {0}; j < lenght-(i+1); ++j) //Change your loop to not re-check elements that are already sorted.
        {
            if (array[j] > array[j+1])
            {
                std::swap(array[j],array[j+1]);
                flag = true;
            }         
        }
        if (!flag)
        {
            std::cout << "Early termination on iteration " << i + 1 << std::endl;
            break;
        }
        
    }

    for(auto &&i: array)
    {
        std::cout << i << " ";
    }
 

    return 0;
}