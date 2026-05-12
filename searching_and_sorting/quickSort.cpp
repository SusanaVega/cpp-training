#include <iostream>
#include <random>

class QuickSort {
    public:
        static int partition(int arr[], int low, int high) {
            //int pivotIndex = rand() % (high - low + 1) + low;
            //int pivotValue = arr[pivotIndex];
            int pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr, i, j);
                }
                
            }
                swap(arr, i + 1, high);
                return i + 1;
        }
        static void quickSort(int arr[], int low, int high) {
            if (low < high) {
                int pivotIndex = partition(arr, low, high);
                quickSort(arr, low, pivotIndex - 1);
                quickSort(arr, pivotIndex + 1, high);
            }
         }
        static void swap(int arr[], int i, int j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
};

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort::quickSort(arr, 0, n - 1);

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}




