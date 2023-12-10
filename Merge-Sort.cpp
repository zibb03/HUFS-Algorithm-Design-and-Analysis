#include <iostream>

void Merge(int result[], int a[], int b[], int sizeA, int sizeB) {
    int i = 0, j = 0, k = 0; 
    // let i be the first unprocessed element in a
    // let j be the first unprocessed element in b
    // k = output location in result[]

    // a[] and b[] are not exhausted
    while (i < sizeA && j < sizeB) {
        if (a[i] < b[j]) {
            // Copy smallest over and shift
            result[k++] = a[i++];
        } else {
            // Copy smallest over and shift
            result[k++] = b[j++];
        }
    }

    //  a[] is exhausted
    while (j < sizeB) {
        result[k++] = b[j++];
    }

    // b[] is exhausted
    while (i < sizeA) {
        result[k++] = a[i++];
    }
}

void MergeSort(int list[], int size) {
    if (size > 1) {
        int firstLength = size / 2;
        int secondLength = size - firstLength;

        int* one = new int[firstLength];
        int* two = new int[secondLength];

        // Copy the first half of list into a new array
        for (int n = 0; n < firstLength; n++) {
            one[n] = list[n];
        }

        // Copy the second half of list into a new array
        for (int n = firstLength; n < size; n++) {
            two[n - firstLength] = list[n];
        }

        // Sort the two smaller arrays
        MergeSort(one, firstLength);
        MergeSort(two, secondLength);
        Merge(list, one, two, firstLength, secondLength);

        delete[] one;
        delete[] two;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}