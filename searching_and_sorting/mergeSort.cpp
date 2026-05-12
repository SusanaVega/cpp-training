#include <iostream>
class MergeSort{
    public:
        static void merge(int arr[], int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            // Temporary arrays
            int L[n1], R[n2];

            // Copy data to temporary arrays
            for (int i = 0; i < n1; ++i)
                L[i] = arr[left + i];
            for (int j = 0; j < n2; ++j)
                R[j] = arr[mid + 1 + j];

            // Merge
            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            // Copy remaining elements of L[] and R[], if any
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        static void mergeSort(int arr[], int left, int right) {
            if (left < right) {
                int mid = (left + right) / 2;

                // Sort the halves
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                // Merge the sorted halves
                merge(arr, left, mid, right);
            }
        }
};

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort::mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted Array: \n";
    for (int i = 0; i < arr_size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}