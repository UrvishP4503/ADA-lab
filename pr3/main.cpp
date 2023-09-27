#include "max_heap.hpp"
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    // 17, 16, 13, 14, 7, 9, 11, 5, 12, 8, 1, 4, 3, 6, 10
    // Max_heap<int> test1 = {50, 54, 53, 52, 55};
    // int arr[] = {1, 23, 4, 3};
    // test1.add(arr, 4);
    // test1.print();

    std::vector<int> arr = {9, 4, 7, 1, -2, 6, 5};
    Max_heap<int> test2 = arr;
    test2.print();

    for (int i = 5 / 2; i >= 0; i--) {
        test2.heapify(i);
    }

    test2.print();
    test2.heap_sort();
    test2.print();
    return 0;
}
