#include <iostream>


int binarySearch(int array[],int size, int target) { 
    int left = 0;
    int right = size - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (array[mid] == target)
            {
                return mid;
            }
            if (array[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    return -1;
}


int main()
{
    int arr[] {-2, 4, 6, 7, 9, 11};
    int target{1};
    int size {sizeof(arr)/sizeof(arr[0])};
    int result = binarySearch(arr, size,target);

    if (result != -1)
    {
        std::cout << "The target " << target << " was found at index: " << result << std::endl;
    } 
    else
    {
        std::cout << "The target " << target << " was not found in the array." << std::endl;
    }
    return 0;
}