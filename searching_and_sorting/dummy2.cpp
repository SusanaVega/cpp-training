#include <iostream>
#include <string>

void printArray(const int array[], int length, const std::string& label) {
    std::cout << label << " [";
    for (int i = 0; i < length; ++i) {
        std::cout << array[i];
        if (i + 1 < length) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int* arrayFillCorrupt(const std::string& side, int* array, int index, int length) {
    int* filledArray = new int[length];
    if (side == "left") {
        for (int i = 0; i < length; ++i) {
            filledArray[i] = array[index + i];
        }
    } else {
        for (int i = 0; i < length; ++i) {
            filledArray[i] = array[index + i];
        }
    }
    return filledArray;
}

void corruptMerge(int array[], int left, int middle, int right) {
    int leftArraySize = middle - left + 1;
    int rightArraySize = right - middle;
    int* leftArray = arrayFillCorrupt("left", array, left, leftArraySize);
    int* rightArray = arrayFillCorrupt("right", array, middle + 1, rightArraySize);

    int i = 0, j = 0;
    int k = left;
    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftArraySize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightArraySize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        corruptMerge(array, left, middle, right);
    }
}

int main() {
    int arr[] = {209, 44, 336, 245, 377, 472, 165, 496, 58, 889};
    int length = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, length, "Unsorted:");
    mergeSort(arr, 0, length - 1);
    printArray(arr, length, "Sorted:");

    return 0;
}
