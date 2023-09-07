#include <iostream>

int binary_search(int arr[], int key, int len) {
    int mid, low = 0, high = len;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key >= arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int linear_search(int arr[], int key, int len) {
    for (int i = 0; i < len; i++) {
        if (key == arr[i]) {
            return i;
        }
    }

    return -1;
}