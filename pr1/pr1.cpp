#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

// Function that performs insertion sort.
void insertion_sort(std::vector<int> &arr, int len) {
    for (int i = 1; i < len; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

// Function that performs selection sort.
void selection_sort(std::vector<int> &arr, int len) {
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
void bubble_sort(std::vector<int> &arr, int len) {
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

// A helper function for quicksort to get partitioning index.
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function that performs quick sort.
void quick_sort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Helper function for merge sort.
void merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function that performs merge sort.
void merge_sort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(int argc, char const *argv[]) {

    std::vector<int> inputTwentyFourThousand(24000);
    std::vector<std::chrono::duration<double, std::milli>> ans;
    for (int v = 24000; v > -1; --v) {
        inputTwentyFourThousand[24000 - v] = v;
    }

    for (int i = 4; i <= 24; i += 2) {

        std::vector<int> slice(inputTwentyFourThousand);

        auto start = std::chrono::system_clock::now();
        bubble_sort(slice, i * 1000);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;
        ans.push_back(elapsed_seconds);
    }

    for (int i = 4; i <= 24; i += 2) {

        std::vector<int> slice(inputTwentyFourThousand);

        auto start = std::chrono::system_clock::now();
        insertion_sort(slice, i * 1000);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

        ans.push_back(elapsed_seconds);
    }

    for (int i = 4; i <= 24; i += 2) {

        std::vector<int> slice(inputTwentyFourThousand);

        auto start = std::chrono::system_clock::now();
        selection_sort(slice, i * 1000);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

        ans.push_back(elapsed_seconds);
    }

    for (int i = 4; i <= 24; i += 2) {

        std::vector<int> slice(inputTwentyFourThousand);

        auto start = std::chrono::system_clock::now();
        merge_sort(slice, 0, (i * 1000) - 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

        ans.push_back(elapsed_seconds);
    }

    for (int i = 4; i <= 24; i += 2) {

        std::vector<int> slice(inputTwentyFourThousand);

        auto start = std::chrono::system_clock::now();
        quick_sort(slice, 0, (i * 1000) - 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

        ans.push_back(elapsed_seconds);
    }

    std::cout << "+----------+---------------+---------------+---------------+---------------+---------------+" << std::endl;
    std::cout << "|" << std::setw(10) << "Number"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::endl
              << "|" << std::setw(10) << "of inputs"
              << "|" << std::setw(15) << "bubble sort"
              << "|" << std::setw(15) << "insertion sort"
              << "|" << std::setw(15) << "selection sort"
              << "|" << std::setw(15) << "merge sort"
              << "|" << std::setw(15) << "quick sort"
              << "|" << std::endl;
    std::cout << "+----------+---------------+---------------+---------------+---------------+---------------+" << std::endl;

    for (int i = 0; i < 11; i++) {
        std::cout << "|" << std::setw(10) << 4000 + (i * 2000) << "|"
                  << std::setw(11) << ans[i].count() << " ms |"
                  << std::setw(11) << ans[i + 11].count() << " ms |"
                  << std::setw(11) << ans[i + 22].count() << " ms |"
                  << std::setw(11) << ans[i + 33].count() << " ms |"
                  << std::setw(11) << ans[i + 44].count() << " ms |" << std::endl;
        std::cout << "+----------+---------------+---------------+---------------+---------------+---------------+" << std::endl;
    }

    return 0;
}
