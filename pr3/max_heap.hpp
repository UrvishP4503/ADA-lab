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
    inline Max_heap() {}
    Max_heap(T element);
    Max_heap(std::initializer_list<T> initial_list);
    void add(T element);
    void add(T elements[], int length);
    void print();
};

template <class T>
Max_heap<T>::Max_heap(T element) {
    this->heap.push_back(element);
    this->size++;
}

template <typename T>
Max_heap<T>::Max_heap(std::initializer_list<T> initial_list) {
    for (const T &element : initial_list) {
        this->size++;
        this->heap.push_back(element);

        int child = this->size;
        while (child > 1) {
            int parent = child / 2;

            if (this->heap[child - 1] > this->heap[parent - 1]) {
                std::swap(this->heap[child - 1], this->heap[parent - 1]);
            } else {
                break;
            }

            child = parent;
        }
    }
}

// template <class T>
// void add(T element) {
//     int child = size++;
//     while (child > 1) {
//         int parent = child / 2;

//         if (heap[child - 1] > heap[parent - 1]) {
//             std::swap(heap[child - 1], heap[parent - 1]);
//         } else {
//             break;
//         }

//         child = parent;
//     }
// }

template <class T>
void Max_heap<T>::add(T element[], int length) {
    for (int i = 0; i < length; i++) {
        this->size++;
        this->heap.push_back(element[i]);

        int child = this->size;
        while (child > 1) {
            int parent = child / 2;

            if (this->heap[child - 1] > this->heap[parent - 1]) {
                std::swap(this->heap[child - 1], this->heap[parent - 1]);
            } else {
                break;
            }

            child = parent;
        }
    }
}

template <class T>
void Max_heap<T>::print() {
    for (const T &element : this->heap) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
