#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Perform a binary search in an integer vector.
 * 
 * This function searches for the specified 'key' in given 'arr' of integers.
 * 
 * @param arr The vector of inters to search.
 * @param key The integer value to find.
 * @param len The number of elemets in the vector. 
 * 
 * @return The index of 'key' if found; -1 if not found. 
 */
int binary_search(std::vector<int> arr, int key, int len) {
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

/**
 * @brief Perform a linear search in an integer vector.
 *
 * This function searches for the specified 'key' in the given 'arr' of integers.
 *
 * @param arr The vector of integers to search.
 * @param key The integer value to find.
 * @param len The number of elements in the vector.
 *
 * @return The index of 'key' if found; -1 if not found.
 */
int linear_search(std::vector<int> arr, int key, int len) {
    for (int i = 0; i < len; i++) {
        if (key == arr[i]) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    std::vector<int> inputTenThousand(10000);

    for (int v = 0; v < 10000; ++v) {
        inputTenThousand[v] = v;
    }

    std::cout << "+----------+--------------+" << std::endl;
    std::cout << "|" << std::setw(10) << "Number"
              << "|" << std::setw(14) << "Time taken by"
              << "|" << std::endl
              << "|" << std::setw(10) << "of inputs"
              << "|" << std::setw(14) << "Linear search"
              << "|" << std::endl;
    std::cout << "+----------+--------------+" << std::endl;
    for (int i = 1; i <= 10; ++i) {

        auto start = std::chrono::system_clock::now();
        auto t = linear_search(inputTenThousand, i * 1000, i * 1000 + 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

        std::cout << "|" << std::setw(10) << i * 1000 << "|" << std::setw(14) << elapsed_seconds.count() << "|" << std::endl;
        std::cout << "+----------+--------------+" << std::endl;
    }

    int keys[] = {123, 789, 555, 2000, 8765, 500, 4321, 8000, 111, 900};

    std::cout << "+----------+--------------+" << std::endl;
    std::cout << "|" << std::setw(10) << "Key"
              << "|" << std::setw(14) << "Time taken by"
              << "|" << std::endl
              << "|" << std::setw(10) << " "
              << "|" << std::setw(14) << "Binary search"
              << "|" << std::endl;
    std::cout << "+----------+--------------+" << std::endl;
    for (int i = 1; i <= 10; ++i) {

        auto start = std::chrono::system_clock::now();
        auto temp = (inputTenThousand, keys[i - 1], i * 1000);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;

        std::cout << "|" << std::setw(10) << keys[i - 1] << "|" << std::setw(14) << elapsed_seconds.count() << "|" << std::endl;
        std::cout << "+----------+--------------+" << std::endl;
    }

    return 0;
}
