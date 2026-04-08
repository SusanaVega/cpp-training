#include <iostream>

/*Problem
    You are tasked to find a number in an array. You know the person that hid the number has a preference for odd numbers. 
    Meaning they are more likely to hide the number at an odd index. In this search algorithm, you should 
    1st check all odd indices for the search target, and, if not found, then check all even indices.
    Basically, we are cutting down our search radius by half. 
    Create the method evenOrOdd that takes an unsorted array of integers and a target (also an integer). 
    The method should return an integer representing the index of the target in the array. 
    If the target is not found, return -1.
*/


// Implement various search and sort algorithms to streamline operations.
// refine and re-engineer the sorting and searching methods of this behemoth, 
// enhancing its efficiency and ensuring Techville remains the digital utopia for its citizens!

int evenOrOdd(int arr[], int size, int target)
{
    int result{-1};
    bool found {false};
    //search target on odd indices
    for (int i = 1; i < size; i+=2)
    {
        if (target == arr[i])
        {
            result = i;
            found = true;
            break;
        }
        
    }

    //search target on even indices
    if (!found)
    {
        for (int i = 0; i < size; i+=2)
        {
            if (target == arr[i])
            {
                result = i;
                break;
            }
        }
    }

    return result;
}

int main(){
    int target{3};
    int arr[] = {20, -45, 7, 3325, -1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = evenOrOdd(arr,size,target);
if (result != -1){
    std::cout << "The target " << target << " was found at index: " << result << std::endl;
} else
{
    std::cout << "The target " << target << " was not found in the array." << std::endl;
}



    return 0;
}