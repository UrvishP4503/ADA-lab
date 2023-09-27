#pragma 0
#define MAX_HEAP_HPP

#include <iostream>
#include <vector>

template <typename T>
class Max_heap {
private:
    std::vector<T> heap;
    int size{0};

public:
    Max_heap(std::vector<int> &vec);
    void heapify(int i);
    void heap_sort();
    // inline Max_heap() {}
    // Max_heap(std::initializer_list<T> initial_list);
    // void add(T elements[], int length);
    void print();
};

template <class T>
Max_heap<T>::Max_heap(std::vector<int> &vec) {
    for (const T &element : vec) {
        this->size++;
        this->heap.push_back(element);

        int child = this->size;
        while (child > 1) {
            int parent = child / 2;
            if (this->heap[child - 1] > this->heap[parent - 1]) {
                std::swap(this->heap[child - 1], this->heap[parent - 1]);
                child = parent;
            } else {
                break;
            }
        }
    }
}

template <class T>
void Max_heap<T>::heapify(int i) {

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < this->size && this->heap[largest] < this->heap[left]) {
        largest = left;
    }

    if (right < this->size && this->heap[largest] < this->heap[right]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(this->heap[i], this->heap[largest]);
        this->heapify(largest);
    }
}

template <class T>
void Max_heap<T>::heap_sort() {
    if (this->size <= 1) {
        return;
    }

    int temp = this->size;
    int len = this->size;
    while (len >= 1) {
        int temp = len - 1;
        std::swap(this->heap[0], this->heap[temp]);
        len--;
        this->size--;
        this->heapify(0);
    }
    this->size = temp;
}

// template <typename T>
// Max_heap<T>::Max_heap(std::initializer_list<T> initial_list) {
//     for (const T &element : initial_list) {
//         this->size++;
//         this->heap.push_back(element);

//         int child = this->size;
//         while (child > 1) {
//             int parent = child / 2;

//             if (this->heap[child - 1] > this->heap[parent - 1]) {
//                 std::swap(this->heap[child - 1], this->heap[parent - 1]);
//                 child = parent;
//             } else {
//                 break;
//             }
//         }
//     }
// }

// template <class T>
// void Max_heap<T>::add(T element[], int length) {
//     for (int i = 0; i < length; i++) {
//         this->size++;
//         this->heap.push_back(element[i]);

//         int child = this->size;
//         while (child > 1) {
//             int parent = child / 2;

//             if (this->heap[child - 1] > this->heap[parent - 1]) {
//                 std::swap(this->heap[child - 1], this->heap[parent - 1]);
//             } else {
//                 break;
//             }
//         }
//     }
// }

template <class T>
void Max_heap<T>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->heap.at(i) << " ";
    }
    std::cout << std::endl;
}
