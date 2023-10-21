#include <iostream>
#include <vector>

#include "max_heap.hpp"


int main(int argc, char const *argv[]) {
    // 17, 16, 13, 14, 7, 9, 11, 5, 12, 8, 1, 4, 3, 6, 10
    // Max_heap<int> test1 = {50, 54, 53, 52, 55};
    // int arr[] = {1, 23, 4, 3};
    // test1.add(arr, 4);
    // test1.print();

    std::vector<int> arr = {17, 42, 89, 5, 61, 33, 98, 12, 77, 25};
    Max_heap<int> test2 = arr;

    std::cout << "Given list of elements: ";
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // for (int i = 15 / 2; i >= 0; i--) {
    //     test2.heapify(i);
    // }

    std::cout << "After heap sort: ";
    test2.heap_sort();
    test2.print();
    return 0;
}
