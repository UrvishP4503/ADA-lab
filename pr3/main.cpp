#include "max_heap.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    Max_heap<int> test1 = {1, 3, 9, 4};
    Max_heap<int> test2 = Max_heap(3);
    int arr[] = {1, 23, 4, 5};
    test2.add(arr, 4);
    test1.print();
    test2.print();
    return 0;
}
