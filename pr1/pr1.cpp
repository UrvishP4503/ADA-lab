#include <chrono>
#include <iostream>

void bubble_sort(int arr[], int len);
void selection_sort(int arr[], int len);
void insertion_sort(int arr[], int len);
void merge_sort(int A[], int B[], int n);
void merge(int B[], int iBegin, int iMiddle, int iEnd, int A[]);
void copy_array(int A[], int iBegin, int iEnd, int B[]);
void split_merge(int B[], int iBegin, int iEnd, int A[]);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void time_analysis_of_all() {
    int inputTenThousand[10000];

    for (int v = 9999; v > -1; --v) {
        inputTenThousand[v] = v;
    }
    auto start = std::chrono::system_clock::now();

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

    std::cout << "elapsed time: " << elapsed_seconds.count() << " milli seconds"
              << std::endl;
}

int main(int argc, char const *argv[]) {
    return 0;
}

// Function that performs insertion sort.
void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

// Function that performs selection sort.
void selection_sort(int arr[], int len) {
    int min = 0;
    for (int i = 0; i < len; i++) {
        min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (i != min)
            std::swap(arr[i], arr[min]);
    }
}

// Function that performs selection sort.
void bubble_sort(int arr[], int len) {
    bool is_sorting = false;
    for (int i = 0; i < len - 1; i++) {
        is_sorting = false;
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                is_sorting = true;
            }
        }
        if (!is_sorting)
            break;
    }
}

// Function that performs merge sort.
void merge_sort(int A[], int B[], int n) {
    copy_array(A, 0, n, B);  // One-time copy of A[] to B[]
    split_merge(B, 0, n, A); // Sort data from B[] into A[]
}

void split_merge(int B[], int iBegin, int iEnd, int A[]) {
    if (iEnd - iBegin <= 1) // If run size == 1, consider it sorted
        return;

    int iMiddle = (iEnd + iBegin) / 2;

    split_merge(A, iBegin, iMiddle, B);
    split_merge(A, iMiddle, iEnd, B);

    merge(B, iBegin, iMiddle, iEnd, A);
}

// A helper function for merge sort to merge sorted arrays.
void merge(int B[], int iBegin, int iMiddle, int iEnd, int A[]) {
    int i = iBegin, j = iMiddle;

    for (int k = iBegin; k < iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || B[i] <= B[j])) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j++;
        }
    }
}

// It copys the elements of array to other empty array in given range.
void copy_array(int A[], int start, int end, int B[]) {
    for (int k = start; k < end; k++)
        B[k] = A[k];
}

// Helper fuction for selection sort to find pivot or partition element.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function that performs quick sort.
void quick_sort(int arr[], int low, int high) {
    if (low > -1 && high > -1 && low < high) {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}
